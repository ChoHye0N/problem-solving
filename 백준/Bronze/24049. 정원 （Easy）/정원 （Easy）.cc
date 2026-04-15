#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++){
        cin >> arr[i][0];
    }
    for (int i = 1; i <= m; i++){
        cin >> arr[0][i];
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (arr[i][j - 1] == arr[i - 1][j]) arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    
    cout << arr[n][m];
    
    return 0;
}