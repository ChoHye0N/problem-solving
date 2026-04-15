#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        if (arr[i][i] != 0){
            cout << -1;
            return 0;
        }
        
        for (int j = 0; j < n; j++){
            if (arr[i][j] != -arr[j][i]){
                cout << -1;
                return 0;
            }
        }
    }
    
    vector<int> ans;
    unordered_set<int> check;
    for (int i = 0; i < n; i++){
        int currN = 0;
        
        for (int j = 0; j < n; j++){
            if (arr[i][j] == -1) currN++;
        }
        
        ans.push_back(currN + 1);
        
        if (check.count(currN + 1)){
            cout << -1;
            return 0;
        }
        check.insert(currN + 1);
    }
    
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    
    return 0;
}