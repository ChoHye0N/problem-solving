#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> square(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            square[i][j] = row[j] - '0';
        }
    }
    
    int maxSize = min(n, m);

    while (maxSize > 1) {
        for (int i = 0; i + maxSize - 1 < n; i++) {
            for (int j = 0; j + maxSize - 1 < m; j++) {
                
                int x1 = i, y1 = j;
                int x2 = i, y2 = j + maxSize - 1;
                int x3 = i + maxSize - 1, y3 = j;
                int x4 = i + maxSize - 1, y4 = j + maxSize - 1;
        
                if (square[x1][y1] == square[x2][y2] &&
                    square[x1][y1] == square[x3][y3] &&
                    square[x1][y1] == square[x4][y4]) {
                    cout << maxSize * maxSize;
                    return 0;
                }
            }
        }
        maxSize--;
    }
    
    cout << 1;
    
    return 0;
}