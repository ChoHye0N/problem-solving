#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() 
{
    int n, m, r;
    cin >> n >> m >> r;
    
    vector<int> item(n);
    for (int i = 0; i < n; i++){
        cin >> item[i];
    }
    
    vector<vector<int>> arr(n, vector<int>(n, INF));
    for (int i = 0; i < r; i++){
        int a, b, w;
        cin >> a >> b >> w;
        
        a--, b--;
        arr[a][b] = w, arr[b][a] = w;
    }
    
    for (int i = 0; i < n; i++){
        arr[i][i] = 0;
    }
    
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][k] != INF && arr[k][j] != INF){
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        int sum = item[i];
        
        for (int j = 0; j < n; j++){
            if (arr[i][j] <= m && j != i) sum += item[j];
        }
        
        ans = max(ans, sum);
    }
    
    cout << ans;
    
    return 0;
}