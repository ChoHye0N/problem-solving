#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int idx = 0; idx < t; idx++){
        bool flag = true;
        
        set<int> check;
        
        vector<vector<int>> arr(9, vector<int>(9));
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cin >> arr[i][j];
            }
        }
        
        // row check
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                check.insert(arr[i][j]);
            }
            if (check.size() != 9) flag = false;
            check.clear();
        }
        
        // column check
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                check.insert(arr[j][i]);
            }
            if (check.size() != 9) flag = false;
            check.clear();
        }
        
        // box check
        for (int i = 0; i < 9; i += 3){
            for (int j = 0; j < 9; j += 3){
                int sum = 0;
                
                for (int k = 0; k < 3; k++){
                    for (int l = 0; l < 3; l++){
                        check.insert(arr[i + k][j + l]);
                    }
                }
                if (check.size() != 9){
                    flag = false;
                }
                check.clear();
            }
        }
        
        cout << "Case " << idx + 1 << ": " <<(flag ? "CORRECT\n" : "INCORRECT\n");
    }
    
    return 0;
}