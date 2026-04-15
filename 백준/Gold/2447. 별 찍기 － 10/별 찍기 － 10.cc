#include <bits/stdc++.h>

using namespace std;

void star(vector<string> &board, int x, int y, int n){
    if (n == 1) {
        board[x][y] = '*';
        return;
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == 1 && j == 1) continue;
            star(board, x + i * (n / 3), y + j * (n / 3), n / 3);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> board(n, string(n, ' '));
    star(board, 0, 0, n);
    
    for (int i = 0; i < n; i++){
        cout << board[i] << '\n';
    }
    
    return 0;
}