#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    int n;
    cin >> n;

    vector<llg> dp(n + 1, 0);
    dp[1] = 4, dp[2] = 6;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}