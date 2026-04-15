#include <bits/stdc++.h>
using namespace std;
using v2 = vector<vector<int>>;

int ans = 0, n, m;

void bfs(queue<pair<int, int>>& q,  v2& arr, v2& comb) {
    int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i], ny = curr.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
                arr[nx][ny] = 2;
                q.push({ nx, ny });
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) sum++;
        }
    }
    
    ans = max(ans, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    v2 comb, arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n * m; i++) {
        if (arr[i / m][i % m] != 0) continue;

        for (int j = i + 1; j < n * m; j++) {
            if (arr[j / m][j % m] != 0) continue;

            for (int k = j + 1; k < n * m; k++) {
                if (arr[k / m][k % m] != 0) continue;

                comb.push_back({ i, j, k });
            }
        }
    }

    for (int t = 0; t < comb.size(); t++) {
        v2 trr = arr;
        queue<pair<int, int>> q;

        for (int i = 0; i < 3; i++) {
            trr[comb[t][i] / m][comb[t][i] % m] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (trr[i][j] == 2) q.push({i, j});
            }
        }

        bfs(q, trr, comb);
    }
    
    cout << ans;

    return 0;
}