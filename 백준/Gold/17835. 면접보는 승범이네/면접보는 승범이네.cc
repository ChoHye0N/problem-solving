#include <bits/stdc++.h>
using namespace std;

using llg = long long;
const llg INF = LLONG_MAX;

priority_queue<pair<llg, int>, vector<pair<llg, int>>, greater<>> pq;

void djk(vector<vector<pair<int, int>>>& arr, vector<llg>& dist, vector<int>& nodes) {
    for (int k : nodes) {
        dist[k] = 0;
        pq.push({ 0, k });
    }

    while (!pq.empty()) {
        llg d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& p : arr[u]) {
            int v = p.first;
            llg w = p.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<llg> dist(n + 1, INF);
    vector<vector<pair<int, int>>> arr(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        arr[v].push_back({ u, c });
    }

    vector<int> nodes(k);
    for (int i = 0; i < k; i++) {
        cin >> nodes[i];
    }

    djk(arr, dist, nodes);

    int idx = -1;
    llg maxD = -1;

    for (int i = 1; i <= n; i++) {
        if (dist[i] != LLONG_MAX && maxD < dist[i]) {
            maxD = dist[i];
            idx = i;
        }
    }

    cout << idx << '\n' << maxD;

    return 0;
}