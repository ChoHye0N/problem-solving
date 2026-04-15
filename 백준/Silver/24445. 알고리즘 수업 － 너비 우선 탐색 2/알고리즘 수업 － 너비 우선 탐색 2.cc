#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<int>>& arr, vector<int>& visited) {
    queue<int> q;
    int d = 1;

    q.push(n - 1);
    visited[n - 1] = d;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < arr[curr].size(); i++) {
            if (visited[arr[curr][i]] == 0) {
                q.push(arr[curr][i]);
                visited[arr[curr][i]] = ++d;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> arr(n);
    vector<int> visited(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        u--, v--;
        arr[u].push_back(v), arr[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        sort(arr[i].rbegin(), arr[i].rend());
    }

    bfs(r, arr, visited);

    for (int i = 0; i < n; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}