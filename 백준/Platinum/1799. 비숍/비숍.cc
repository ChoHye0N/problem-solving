#include <bits/stdc++.h>

using namespace std;

int n, maxCount[2] = {0, 0};
bool diag1[30], diag2[30];
int board[10][10];

void back(int clr, int idx, int cnt){
    if (idx >= n * n){
        maxCount[clr] = max(maxCount[clr], cnt);
        return;
    }
    
    int x = idx / n, y = idx % n;
    
    if ((x + y) % 2 == clr && board[x][y] == 1){
        if (!diag1[x + y] && !diag2[x - y + n - 1]){
            diag1[x + y] = diag2[x - y + n - 1] = true;
            back(clr, idx + 1, cnt + 1);
            diag1[x + y] = diag2[x - y + n - 1] = false;
        }
    }
    
    back(clr, idx + 1, cnt);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    
    back(0, 0, 0);
    back(1, 0, 0);
    
    cout << maxCount[0] + maxCount[1];
    
    return 0;
}