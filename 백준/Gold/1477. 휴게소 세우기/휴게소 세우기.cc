#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long l;
	cin >> n >> m >> l;

	vector<long long> pos(n);
	for (int i = 0; i < n; i++) cin >> pos[i];

	sort(pos.begin(), pos.end());

	vector<long long> gap;
	long long prev = 0;
	for (int i = 0; i < n; i++) {
		gap.push_back(pos[i] - prev);
		prev = pos[i];
	}
	gap.push_back(l - prev);

	long long lo = 1, hi = l, ans = l;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;

		long long need = 0;
		for (long long g : gap) {
			need += (g - 1) / mid;
		}

		if (need <= m) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << ans;

	return 0;
}
