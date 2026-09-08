#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> cnt(101, vector<int>(101, 0));

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				cnt[x][y]++;
			}
		}
	}

	int ans = 0;
	for (int x = 1; x <= 100; x++) {
		for (int y = 1; y <= 100; y++) {
			if (cnt[x][y] > m) ans++;
		}
	}

	cout << ans;

	return 0;
}
