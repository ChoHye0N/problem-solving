#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<int> djk(vector<vector<pair<int, int>>>& arr, int n, int s) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

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
                pq.push({ dist[v] , v });
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> arr(n + 1), rArr(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        arr[u].push_back({ v, w });
        rArr[v].push_back({ u, w });
    }

    vector<int> dist1 = djk(arr, n, x), dist2 = djk(rArr, n, x);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (dist1[i] != INF && dist2[i] != INF) {
            ans = max(ans, dist1[i] + dist2[i]);
        }
    }

    cout << ans;

    return 0;
}