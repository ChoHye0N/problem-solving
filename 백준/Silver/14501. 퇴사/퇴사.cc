#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        int f = arr[i - 1].first, s = arr[i - 1].second;

        if (i + f - 1 <= n) {
            dp[i + f - 1] = max(dp[i + f - 1], dp[i - 1] + s);
        }
    }

    cout << dp[n];

    return 0;
}