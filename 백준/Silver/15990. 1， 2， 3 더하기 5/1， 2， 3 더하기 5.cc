#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int MOD = 1000000009;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int maxN = *max_element(arr.begin(), arr.end());
    vector<vector<llg>> dp(maxN + 1, vector<llg>(4, 0));
    dp[1][1] = 1, dp[2][2] = 1, dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;
    
    for (int i = 4; i <= maxN; i++){
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }
    
    for (int i = 0; i < n; i++){
        llg num = arr[i];
        cout << (dp[num][1] + dp[num][2] + dp[num][3]) % MOD << '\n';
    }
    
    return 0;
}