#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    cin >> m >> k;
    vector<vector<int>> brr(m, vector<int>(k));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < k; j++){
            cin >> brr[i][j];
        }
    }

    vector<vector<int>> res(n, vector<int>(k, 0));
    for (int b = 0; b < n; b++){
        for (int c = 0; c < k; c++){
            for (int a = 0; a < m; a++){
                res[b][c] += arr[b][a] * brr[a][c];
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}