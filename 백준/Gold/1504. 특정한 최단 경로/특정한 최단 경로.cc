#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<ll> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src) {
	vector<ll> dist(n + 1, INF);
	dist[src] = 0;

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push({ 0, src });

	while (!pq.empty()) {
		ll d = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (d > dist[u]) continue;

		for (auto& e : adj[u]) {
			int v = e.first, w = e.second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e;
	cin >> n >> e;

	vector<vector<pair<int, int>>> adj(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<ll> from1 = dijkstra(n, adj, 1);
	vector<ll> fromV1 = dijkstra(n, adj, v1);
	vector<ll> fromV2 = dijkstra(n, adj, v2);

	ll path1 = from1[v1] + fromV1[v2] + fromV2[n];
	ll path2 = from1[v2] + fromV2[v1] + fromV1[n];

	ll ans = min(path1, path2);

	if (ans >= INF) cout << -1;
	else cout << ans;

	return 0;
}
