#include <bits/stdc++.h>
using namespace std;

vector<int> stk;
int d = 1;

void dfs(vector<vector<int>>& arr, vector<int>& visited, int s) {
    visited[s] = d++;

    for (int i = 0; i < arr[s].size(); i++) {
        if (visited[arr[s][i]] == 0) dfs(arr, visited, arr[s][i]);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> arr(n + 1);
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (int i = 0; i < arr.size(); i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(arr, visited, r);

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}