#include <bits/stdc++.h>
using namespace std;

int cnt = 1;

void bfs(int n, vector<vector<int>>& arr, vector<int>& visited) {
    queue<int> q;
    q.push(n);
    visited[n] = cnt;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int p : arr[curr]) {
            if (!visited[p]) {
                visited[p] = ++cnt;
                q.push(p);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> visited(n + 1, 0);
    vector<vector<int>> arr(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (auto& p : arr) {
        sort(p.begin(), p.end());
    }

    bfs(r, arr, visited);

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}