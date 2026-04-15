#include <bits/stdc++.h>
using namespace std;
using v3 = vector<vector<vector<int>>>;

int n, m, h;

void bfs(queue<vector<int>>& q, v3& arr, v3& visited) {
    int dz[6] = { 1, -1, 0, 0, 0, 0 }, dy[6] = { 0, 0, 1, -1, 0, 0 },
        dx[6] = { 0, 0, 0, 0, 1, -1 };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = curr[0] + dz[i], ny = curr[1] + dy[i], nx = curr[2] + dx[i];

            if (nz >= 0 && nz < h && ny >= 0 && ny < m &&
                nx >= 0 && nx < n && arr[nz][ny][nx] == 0) {
                arr[nz][ny][nx] = 1;
                visited[nz][ny][nx] = visited[curr[0]][curr[1]][curr[2]] + 1;
                q.push({ nz, ny, nx });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;

    v3 arr(h, vector<vector<int>>(m, vector<int>(n))),
        visited(h, vector<vector<int>>(m, vector<int>(n, 0)));
    queue<vector<int>> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                cin >> arr[i][j][k];
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (arr[i][j][k] == 1) q.push({ i, j, k });
            }
        }
    }

    bfs(q, arr, visited);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (arr[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (visited[i][j][k] > ans) {
                    ans = visited[i][j][k];
                }
            }
        }
    }

    cout << ans;

    return 0;
}