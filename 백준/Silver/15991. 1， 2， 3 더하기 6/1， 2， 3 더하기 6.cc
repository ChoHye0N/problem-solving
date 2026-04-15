#include <bits/stdc++.h>

using namespace std;
using llg = long long;

const int MOD = 1000000009;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    vector<int> dp(50001, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i < 50001; i++){
        dp[i] = ((llg)dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
    
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
      
        llg ans = 0;
        
        if(n % 2 == 0){
            ans = dp[n / 2];
            
            if(n - 2 >= 0) {
                ans = (ans + dp[(n - 2) / 2]) % MOD;
            }
        }
        else {
            ans = dp[(n - 1) / 2];
            
            if(n - 3 >= 0){
                ans = (ans + dp[(n - 3) / 2]) % MOD;
            }
        }
        
        cout << ans % MOD << "\n";
    }
    
    return 0;
}