#include <bits/stdc++.h>

using namespace std;
using llg = long long;
 
const llg MOD = 1000000007;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, h;
    cin >> n >> h;
    
    vector<int> cups(n);
    for (int i = 0; i < n; i++){
        cin >> cups[i];
    }
    
    vector<llg> dp(h + 1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < h; i++){
        if (dp[i] == 0) continue;
        
        for (int j = 0; j < n; j++){
            int next = i + cups[j];
            
            if (next <= h){
                dp[next] = (dp[next] + dp[i]) % MOD;
            }
        }
    }
    
    cout << dp[h];
    return 0;
}