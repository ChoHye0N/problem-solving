#include <bits/stdc++.h>
using namespace std;

int n;

void bfs(int x1, int y1, vector<vector<int>>& visited) {
    queue<pair<int, int>> q;
    q.push({ x1, y1 });
    visited[x1][y1] = 1;

    int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 }, dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                visited[nx][ny] == 0) {
                q.push({ nx, ny });
                visited[nx][ny] = visited[curr.first][curr.second] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        bfs(x1, y1, visited);

        cout << visited[x2][y2] - 1 << '\n';
    }

    return 0;
}