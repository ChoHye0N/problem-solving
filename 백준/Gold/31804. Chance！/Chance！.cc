#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> arr(b + 1, vector<int>(2, -1));
    queue<pair<int, int>> q;

    arr[a][0] = 0;
    q.push({ a, 0 });

    while (!q.empty()) {
        int curr = q.front().first, used = q.front().second;
        q.pop();

        if (curr == b) {
            cout << arr[curr][used];
            return 0;
        }

        int dx[] = { curr + 1, curr * 2, curr * 10 };

        if (dx[0] <= b && arr[dx[0]][used] == -1) {
            arr[dx[0]][used] = arr[curr][used] + 1;
            q.push({ dx[0], used });
        }
        if (dx[1] <= b && arr[dx[1]][used] == -1) {
            arr[dx[1]][used] = arr[curr][used] + 1;
            q.push({ dx[1], used });
        }
        if (used == 0) {
            if (dx[2] <= b && arr[dx[2]][1] == -1) {
                arr[dx[2]][1] = arr[curr][0] + 1;
                q.push({ dx[2], 1 });
            }
        }
    }

    return 0;
}