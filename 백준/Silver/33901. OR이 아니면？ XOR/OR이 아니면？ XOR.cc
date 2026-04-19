#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = 0;
    vector<int> cnt(200000, 0);

    for (int i = 0; i < n; i++) {
        if (i > m) {
            cnt[arr[i - m - 1]]--;
        }

        ans += cnt[(arr[i] ^ k)];
        cnt[arr[i]]++;
    }

    cout << ans;

    return 0;
}