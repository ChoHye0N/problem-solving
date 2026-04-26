#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		dist[--u][--v] = 1;
		dist[v][u] = 1;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++) {
		p[i].first = i + 1;
		p[i].second = 0;

		for (int j = 0; j < n; j++) {
			if (dist[i][j] != INF) {
				p[i].second += dist[i][j];
			}
		}
	}

	sort(p.begin(), p.end(), [](auto& a, auto& b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
		});

	cout << p[0].first;

	return 0;
}