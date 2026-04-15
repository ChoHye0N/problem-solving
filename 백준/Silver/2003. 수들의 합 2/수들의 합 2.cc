#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<llg> prefix(n + 1);
    prefix[0] = 0;

    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        prefix[i] = prefix[i - 1] + tmp;
    }

    int s = 0, e = 0, ans = 0;

    while (s <= e && e <= n) {
        if (prefix[e] - prefix[s] == m) {
            ans++;
            e++;
        }
        else if (prefix[e] - prefix[s] > m) s++;
        else e++;
    }

    cout << ans;

    return 0;
}