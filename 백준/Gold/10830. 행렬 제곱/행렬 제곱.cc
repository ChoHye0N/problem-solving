#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int MOD = 1000;

vector<vector<int>> mat_mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    int len = a.size();
    vector<vector<int>> res(len, vector<int>(len));
    
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            for (int k = 0; k < len; k++){
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    
    return res;
}

vector<vector<int>> mat_pow(vector<vector<int>> arr, llg n) {
    int len = arr.size();
    
    if (n == 0){
        vector<vector<int>> vecI(len, vector<int>(len));
        for (int i = 0; i < len; i++){
            vecI[i][i] = 1;
        }
        
        return vecI;
    }
    
    if (n == 1){
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len; j++){
                arr[i][j] %= MOD;
            }
        }
        
        return arr;
    }

    vector<vector<int>> half = mat_pow(arr, n / 2), ans = mat_mul(half, half);
    
    if (n % 2 == 1) ans = mat_mul(ans, arr);
    
    return ans;
}

int main()
{
    llg n, b;
    cin >> n >> b;
    
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> ans = mat_pow(arr, b);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << ans[i][j] % MOD << ' ';
        }
        cout << '\n';
    }

    return 0;
}