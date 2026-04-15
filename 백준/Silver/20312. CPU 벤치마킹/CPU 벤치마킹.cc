#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int MOD = 1000000007;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n - 1);
    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
    
    vector<llg> dp(n - 1, 0);
    dp[0] = arr[0];
    
    llg ans = arr[0];
    for (int i = 1; i < n - 1; i++){
        dp[i] = (dp[i - 1] * arr[i] + arr[i]) % MOD;
        ans += dp[i];
        ans %= MOD;
    }
    
    cout << ans;
    
    return 0;
}