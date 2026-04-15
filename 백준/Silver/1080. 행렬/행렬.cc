#include <bits/stdc++.h>

using namespace std;

void flip(vector<vector<int>>& matrix, int row, int col) {
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            matrix[i][j] = 1 - matrix[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    
    string row;
    int oper = 0;
    
    for (int i = 0; i < n; i++) {
        getline(cin, row);
        for (int j = 0; j < m; j++) {
            a[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        getline(cin, row);
        for (int j = 0; j < m; j++) {
            b[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] != b[i][j]) {
                flip(a, i, j);
                oper++;
            }
        }
    }

    if(a != b) oper = -1;
    cout << oper << '\n';

    return 0;
}