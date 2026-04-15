#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int r, c, w;
    cin >> r >> c >> w;
    
    vector<vector<int>> dp(r + w, vector<int>(r + w, 0));

    for (int i = 0; i < r + w; i++) {
        dp[i][0] = 1; 
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    int total = 0;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j <= i; j++) {
            total += dp[r + i - 1][c + j - 1];
        }
    }
    
    cout << total;
    
    return 0;
}