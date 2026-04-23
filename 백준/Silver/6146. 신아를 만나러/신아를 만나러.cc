#include <bits/stdc++.h>
using namespace std;

int x, y, n;
int arr[1001][1001], visited[1001][1001];

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 500, 500 });
    visited[500][500] = 1;

    int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];

            if (nx >= 0 && nx < 1001 && ny >= 0 && ny < 1001 &&
                visited[nx][ny] == 0 && arr[nx][ny] == 0) {
                q.push({ nx, ny });
                visited[nx][ny] = visited[curr.first][curr.second] + 1;

                if (nx == 500 + x && ny == y) {
                    return;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        arr[500 + a][500 + b] = 1;
    }

    bfs();

    cout << visited[500 + x][500 + y] - 1;

    return 0;
}