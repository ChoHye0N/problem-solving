#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; i++){
            cin >> arr[i][0] >> arr[i][1];
        }
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (arr[i][1] > arr[j][1]){
                    ans++;
                }
            }
        }
        
        printf("Case #%d: %d\n", i + 1, ans);
    }
    
    return 0;
}