#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<bool> inS(1001, false);
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		inS[x] = true;
	}

	long long ans = LLONG_MAX;

	for (int x = 1; x <= n; x++) {
		if (inS[x]) continue;
		if ((long long)x * x * x - n > ans) break;

		for (int y = x; y <= n; y++) {
			if (inS[y]) continue;
			if ((long long)x * y * y - n > ans) break;

			for (int z = y; z <= n; z++) {
				if (inS[z]) continue;

				long long prod = (long long)x * y * z;
				ans = min(ans, llabs(prod - n));

				if (prod - n > ans) break;
			}
		}
	}

	cout << ans;

	return 0;
}
