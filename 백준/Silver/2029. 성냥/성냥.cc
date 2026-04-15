#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<string> arr(10);
    for (int i = 0; i < 10; i++){
        cin >> arr[i];
    }
    
    vector<vector<bool>> row(4, vector<bool>(3, false)), 
        col(3, vector<bool>(4, false));
    int sk = 24;
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            if (arr[i * 3][j * 3 + 1] == '-'){
                row[i][j] = true;
                sk--;
            }
        }
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (arr[i * 3 + 1][j * 3] == '|'){
                col[i][j] = true;
                sk--;
            }
        }
    }
    
    int box = 0;
    
    // 1x1 box
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (row[i][j] && row[i + 1][j] &&
                col[i][j] && col[i][j + 1]){
                box++;
            }
        }
    }
    
    // 2x2 box
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (row[i][j] && row[i][j + 1] &&
                row[i + 2][j] && row[i + 2][j + 1] &&
                col[i][j] && col[i + 1][j] &&
                col[i][j + 2] && col[i + 1][j + 2]){
                box++;
            }
        }
    }
    
    // 3x3 box
    if (row[0][0] && row[0][1] && row[0][2] &&
        row[3][0] && row[3][1] && row[3][2] &&
        col[0][0] && col[1][0] && col[2][0] &&
        col[0][3] && col[1][3] && col[2][3]){
        box++;
    }
    
    cout << sk << ' ' << box << '\n';
    
    return 0;
}