#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    if (k > r * c) {
        cout << 0;
        return 0;
    }

    vector<vector<bool>> visited(c, vector<bool>(r, false));
    int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
    int x = 0, y = 0, cIdx = 0, idx = 1;

    while (idx < k) {
        visited[y][x] = true;
        int nx = x + dx[cIdx], ny = y + dy[cIdx];

        if (nx < 0 || nx >= r || ny < 0 || ny >= c || 
            visited[ny][nx]) {
            cIdx = (cIdx + 1) % 4;
            nx = x + dx[cIdx];
            ny = y + dy[cIdx];
        }
        x = nx, y = ny, idx++;
    }

    cout << x + 1 << ' ' << y + 1;

    return 0;
}