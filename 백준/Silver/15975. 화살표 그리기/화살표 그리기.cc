#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n + 1);
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        
        arr[y].push_back(x);
    }
    
    for (int i = 0; i < n + 1; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    
    long long ans = 0;
    for (int i = 0; i < n + 1; i++){
        int len = arr[i].size();
        if (len <= 1) continue;
        
        for (int j = 0; j < len; j++){
            int left = (j > 0) ? arr[i][j] - arr[i][j - 1] : INT_MAX;
            int right = (j < len - 1) ? arr[i][j + 1] - arr[i][j] : INT_MAX;
            
            ans += min(left, right);
        }
    }
    
    cout << ans;
    
    return 0;
}