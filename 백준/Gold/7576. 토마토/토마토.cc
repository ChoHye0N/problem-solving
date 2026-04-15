#include <bits/stdc++.h>
using namespace std;
using v2 = vector<vector<int>>;

queue<pair<int, int>> q;
int n, m;

void bfs(v2& arr, v2& visited) {
    int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                arr[nx][ny] == 0) {
                arr[nx][ny] = 1;
                q.push({ nx, ny });
                visited[nx][ny] = visited[curr.first][curr.second] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    v2 arr(m, vector<int>(n)), visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) q.push({ i, j });
        }
    }

    bfs(arr, visited);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ans < visited[i][j]) ans = visited[i][j];
        }
    }

    cout << ans;

    return 0;
}