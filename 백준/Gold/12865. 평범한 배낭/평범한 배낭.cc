#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        int w, v;
        cin >> w >> v;
        arr[i] = {w, v};
    }
    
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; i++){
        int w = arr[i].first, v = arr[i].second;
        
        for (int j = k; j >= w; j--){
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    
    cout << dp[k];
    
    return 0;
}