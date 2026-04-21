#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

void djk(vector<vector<pair<int, int>>>& arr, vector<int>& dist, int s, int e) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> vp(dist.size(), 0);

    dist[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& p : arr[u]) {
            int v = p.first, w = p.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
                vp[v] = u;
            }
        }
    }

    cout << dist[e] << '\n';

    int curr = e;
    vector<int> path;

    while (curr != 0) {
        path.push_back(curr);

        if (curr == s) break;
        curr = vp[curr];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (int p : path) {
        cout << p << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> arr(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        arr[u].push_back({ v, w });
    }

    int s, e;
    cin >> s >> e;

    vector<int> dist(n + 1, INF);
    
    djk(arr, dist, s, e);

    return 0;
}