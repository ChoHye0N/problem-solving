#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int LEN = 1000001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<llg> road(LEN, 0);

    for (int i = 0; i < n; i++) {
        int g, x;
        cin >> g >> x;
        road[x] = g;
    }

    for (int i = 1; i < LEN; i++) {
        road[i] += road[i - 1];
    }

    llg ans = 0;
    for (int i = 0; i < LEN; i++) {
        int l = max(0, i - k), r = min(LEN - 1, i + k);
        ans = max(ans, road[r] - (l > 0 ? road[l - 1] : 0));
    }

    cout << ans;

    return 0;
}