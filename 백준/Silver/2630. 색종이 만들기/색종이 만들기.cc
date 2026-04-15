#include <bits/stdc++.h>
using namespace std;

int sumW = 0, sumB = 0;

void dc(int n, int x, int y, int sum, vector<vector<int>> &arr){
    if (sum == n * n){
        sumB++;
        return;
    }
    else if (sum == 0){
        sumW++;
        return;
    }
    
    int h = n / 2, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < h; j++){
            s1 += arr[x + i][y + j];
            s2 += arr[x + i][y + j + h];
            s3 += arr[x + i + h][y + j];
            s4 += arr[x + i + h][y + j + h];
        }
    }
    
    dc(h, x, y, s1, arr);
    dc(h, x, y + h, s2, arr);
    dc(h, x + h, y, s3, arr);
    dc(h, x + h, y + h, s4, arr);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, sum = 0;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    
    dc(n, 0, 0, sum, arr);
    
    cout << sumW << '\n' << sumB;
    
    return 0;
}