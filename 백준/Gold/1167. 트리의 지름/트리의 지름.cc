#include <bits/stdc++.h>
using namespace std;

int maxD = 0, maxN = 0;

void dfs(vector<vector<pair<int, int>>>& arr, vector<bool>& visited, int n, int d) {
    visited[n] = true;

    if (d > maxD) {
        maxD = d;
        maxN = n;
    }

    for (auto e : arr[n]) {
        if (!visited[e.first]) {
            dfs(arr, visited, e.first, d + e.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<bool> visited(n + 1, false);
    vector<vector<pair<int, int>>> arr(n + 1);

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;

        while (true) {
            int v, w;
            cin >> v;

            if (v == -1) break;
            cin >> w;
            arr[u].push_back({ v, w });
        }
    }

    dfs(arr, visited, 1, 0);
    fill(visited.begin(), visited.end(), false);

    maxD = 0;
    dfs(arr, visited, maxN, 0);

    cout << maxD;

    return 0;
}