#include <bits/stdc++.h>
using namespace std;

int w, h, ans;

void bfs(int y, int x, vector<vector<int>>& arr, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;

    int dx[8] = { 1, -1, 0, 0, -1, 1, -1, 1 }, dy[8] = { 0, 0, 1, -1, 1, 1, -1, -1};

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = curr.second + dx[i], ny = curr.first + dy[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h &&
                arr[ny][nx] && !visited[ny][nx]) {
                q.push({ ny, nx });
                visited[ny][nx] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> w >> h;

        if (w == 0 && h == 0) break;

        ans = 0;
        vector<vector<int>> arr(h, vector<int>(w));
        vector<vector<bool>> visited(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (arr[i][j] && !visited[i][j]) {
                    bfs(i, j, arr, visited);
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}