#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int arr[501][501], visited[501][501];

void bfs() {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = 1;

    int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
    int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx > 0 && nx <= n && ny > 0 && ny <= n &&
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

    cin >> n >> m >> x >> y;

    vector<pair<int, int>> ans;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        arr[a][b] = 1;
        ans.push_back({ a, b });
    }

    bfs();

    for (auto p : ans) {
        cout << visited[p.first][p.second] - 1 << ' ';
    }

    return 0;
}