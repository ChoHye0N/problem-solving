#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    vector<llg> dp(101, 1);
    
    for (int i = 4; i < dp.size(); i++){
        dp[i] = dp[i - 3] + dp[i - 2];
    }
    
    while (t--){
        int n;
        cin >> n;
        
        cout << dp[n] << '\n';
    }
    
    return 0;
}