#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<vector<llg>> dp(n + 1, vector<llg>(5, 0));
    for (int i = 0; i < 5; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][4]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][4]) % MOD;
        dp[i][3] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][4] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
    }

    llg ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans;

    return 0;
}