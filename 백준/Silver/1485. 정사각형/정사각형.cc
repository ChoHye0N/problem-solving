#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		vector<ll> x(4), y(4);
		for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];

		vector<ll> dist;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				ll dx = x[i] - x[j], dy = y[i] - y[j];
				dist.push_back(dx * dx + dy * dy);
			}
		}

		sort(dist.begin(), dist.end());

		bool ok = dist[0] > 0 &&
			dist[0] == dist[1] && dist[1] == dist[2] && dist[2] == dist[3] &&
			dist[4] == dist[5] && dist[4] == 2 * dist[0];

		cout << (ok ? 1 : 0) << '\n';
	}

	return 0;
}
