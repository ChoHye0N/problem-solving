#include <bits/stdc++.h>
using namespace std;

// Sum of 0, -1, 1
int total1 = 0, total2 = 0, total3 = 0;

void f(int n, int x, int y, int op, vector<vector<int>> &arr){
    if (op == -1){
        total1++;
        return;
    }
    else if (op == 0){
        total2++;
        return;
    }
    else if (op == 1){
        total3++;
        return;
    }
    
    int h = n / 3, opArr[9];
    for (int i = 0; i < 9; i++) opArr[i] = -2;
    
    for (int i = x; i < x + n; i++){
        for (int j = y; j < y + n; j++){
            int idx = ((i - x) / h) * 3 + ((j - y) / h);
            
            if (opArr[idx] == 2) continue;
            if (opArr[idx] == -2){
                opArr[idx] = arr[i][j];
            }
            if (opArr[idx] != arr[i][j]) opArr[idx] = 2;
        }
    }
    
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            f(h, x + i * h, y + j * h, opArr[idx++], arr);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(n));
    // Option: -1, 0, 1, None => -1, 0, 1, 2;
    int fixed = 2, op = 2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            
            if (i == 0 && j == 0){
                op = arr[i][j];
            }
            else if (op != arr[i][j]) op = 2;
        }
    }
    
    f(n, 0, 0, op, arr);
    
    cout << total1 << '\n' << total2 << '\n' << total3;
    
    return 0;
}