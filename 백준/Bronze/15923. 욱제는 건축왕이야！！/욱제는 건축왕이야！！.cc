#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++){
      for (int j = 0; j < 2; j++){
          cin >> arr[i][j];
      }
    }
    
    int ans = 0;
    for (int i = 1; i < n; i++){
        ans += sqrt(pow(arr[i][0] - arr[i - 1][0], 2) + pow(arr[i][1] - arr[i - 1][1], 2));
    }
    ans += sqrt(pow(arr[n - 1][0] - arr[0][0], 2) + pow(arr[n - 1][1] - arr[0][1], 2));
    
    cout << ans;
    
    return 0;
}