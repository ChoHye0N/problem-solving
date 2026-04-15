#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(3, vector<int>(3, 0));

    int turn = n;
    for (int i = 0; i < 9; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        arr[x][y] = turn;
        
        for (int j = 0; j < 3; j++) {
            if (arr[j][0] == turn && arr[j][1] == turn && arr[j][2] == turn) {
                cout << turn;
                return 0;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (arr[0][j] == turn && arr[1][j] == turn && arr[2][j] == turn) {
                cout << turn;
                return 0;
            }
        }
        if (arr[0][0] == turn && arr[1][1] == turn && arr[2][2] == turn) {
            cout << turn;
            return 0;
        }
        if (arr[0][2] == turn && arr[1][1] == turn && arr[2][0] == turn) {
            cout << turn;
            return 0;
        }

        turn = (turn == 1 ? 2 : 1);
    }

    cout << 0;
    
    return 0;
}