#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (1){
        int n;
        cin >> n;
        
        if (n == 0) break;
        
        int num;
        cin >> num;
        
        vector<int> dp(n, 0);
        dp[0] = num;
        int result = dp[0];
        
        for (int i = 1; i < n; i++){
            cin >> num;
            dp[i] = max(dp[i - 1] + num, num);
            
            if (dp[i] > result){
                result = dp[i];
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}