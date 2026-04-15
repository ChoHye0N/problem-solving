#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<int>> distance(n, vector<int>(m, -1));
    queue<Point> qArr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 2) {
                qArr.push({ i, j });
                distance[i][j] = 0;
            }
        }
    }

    /* BFS */
    while (!qArr.empty()) {
        Point curr = qArr.front();
        qArr.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (maze[nx][ny] == 1 && distance[nx][ny] == -1)) {
                distance[nx][ny] = distance[curr.x][curr.y] + 1;
                qArr.push({ nx, ny });
            }
        }
    }

    /* Print a distance */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 0) {
                cout << 0 << ' ';
            }
            else {
                cout << distance[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}