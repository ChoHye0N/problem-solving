#include <iostream>
#include <vector>

using namespace std;

int sam(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    dp[1][1] = 1;
    dp[1][2] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
    }

    return dp[n][0];
}

int main() {
    int n;
    cin >> n;

    cout << sam(n) << '\n';

    return 0;
}