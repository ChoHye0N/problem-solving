#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() {
    int n;
    cin >> n;
    
    vector<vector<llg>> dp(n + 1, vector<llg>(2, 0));
    dp[1][0] = 0;
    dp[1][1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    
    cout << dp[n][0] + dp[n][1];
    
    return 0;
}