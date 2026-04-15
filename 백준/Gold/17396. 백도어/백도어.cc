#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const llg INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    vector<int> vChecked(n);
    for (int i = 0; i < n; i++) {
        cin >> vChecked[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    vector<llg> dist(n, INF);
    priority_queue<pair<llg, int>, vector<pair<llg, int>>, greater<>> pq;

    dist[0] = 0;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        llg d = pq.top().first, u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& p : adj[u]) {
            int v = p.first, w = p.second;

            if (v != n - 1 && vChecked[v] == 1) continue;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    cout << (dist[n - 1] == INF ? -1 : dist[n - 1]);

    return 0;
}