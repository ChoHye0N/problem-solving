#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int MOD = 1e9 + 9;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    vector<vector<llg>> dp(n + 1, vector<llg>(3));
    dp[1][0] = 0, dp[1][1] = 1, dp[1][2] = 1;

    for (int i = 2; i <= n; i++) {
        llg sum = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;

        dp[i][0] = sum, dp[i][1] = sum, dp[i][2] = sum;
    }

    cout << dp[n][0];

    return 0;
}