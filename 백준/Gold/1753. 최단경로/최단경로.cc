#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int vC, eC, st;
	cin >> vC >> eC >> st;

	vector<vector<pair<int, int>>> arr(vC + 1);
	for (int i = 0; i < eC; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		
		arr[u].push_back({ v, w });
	}

	vector<int> dist(vC + 1, INF);
	dist[st] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, 
		greater<pair<int, int>>> pq;
	pq.push({ 0, st });

	while (!pq.empty()) {
		int d = pq.top().first, u = pq.top().second;
		pq.pop();

		if (d > dist[u]) continue;

		for (auto e : arr[u]) {
			int v = e.first, w = e.second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({ dist[v], v });
			}
		}
	}

	for (int i = 1; i <= vC; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}