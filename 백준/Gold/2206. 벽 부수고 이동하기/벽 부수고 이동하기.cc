#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;

struct State {
    int x, y, check;
};

int bfs(vector<vector<int>>& arr) {
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, 0)));
    queue<State> q;

    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1;

    int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr.x == n - 1 && curr.y == m - 1) {
            return dist[curr.x][curr.y][curr.check];
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (dist[nx][ny][curr.check] == 0 && arr[nx][ny] == 0) {
                q.push({ nx, ny, curr.check });
                dist[nx][ny][curr.check] = dist[curr.x][curr.y][curr.check] + 1;
            }

            if (curr.check == 0 && dist[nx][ny][1] == 0 && arr[nx][ny] == 1) {
                dist[nx][ny][1] = dist[curr.x][curr.y][curr.check] + 1;
                q.push({ nx, ny, 1 });
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++) {
            arr[i][j] = tmp[j] - '0';
        }
    }

    cout << bfs(arr);

    return 0;
}