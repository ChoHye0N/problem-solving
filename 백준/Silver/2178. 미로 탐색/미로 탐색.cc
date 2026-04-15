#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;

void bfs(vector<vector<int>>& arr, vector<vector<int>>& visited) {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0]++;

    int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny]) {
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

    vector<vector<int>> arr(n, vector<int>(m)), visited(n, vector<int>(m, false));

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    bfs(arr, visited);

    cout << visited[n - 1][m - 1];

    return 0;
}