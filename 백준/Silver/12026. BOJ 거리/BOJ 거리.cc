#include <bits/stdc++.h>

using namespace std;

char next_char(char c){
    if (c == 'B') return 'O';
    else if (c == 'O') return 'J';
    return 'B';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string str;
    cin >> n >> str;
    
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++){
        if (dp[i] == INT_MAX) continue;
        char nc = next_char(str[i]);
        
        for (int j = i + 1; j < n; j++){
            if (str[j] == nc){
                int cost = (j - i) * (j - i);
                
                if (dp[i] + cost < dp[j]){
                    dp[j] = dp[i] + cost;
                }
            }
        }
    }
    
    cout << (dp[n - 1] == INT_MAX ? -1 : dp[n - 1]);
    
    return 0;
}