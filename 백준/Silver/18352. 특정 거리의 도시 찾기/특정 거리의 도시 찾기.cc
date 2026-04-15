#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void bfs(vector<vector<pair<int, int>>>& arr, vector<int>& dist, int x) {
    queue<int> q;

    dist[x] = 0;
    q.push(x);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& p : arr[u]) {
            int v = p.first, w = p.second;

            if (dist[v] == INF) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<vector<pair<int, int>>> arr(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w = 1;
        cin >> u >> v;

        arr[u].push_back({ v, w });
    }

    vector<int> dist(n + 1, INF);
    bfs(arr, dist, x);

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());

    if (!ans.empty()) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << '\n';
        }
    }

    else cout << -1;

    return 0;
}