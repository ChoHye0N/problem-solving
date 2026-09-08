#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> tailIdx;
	vector<int> parent(n, -1);

	for (int i = 0; i < n; i++) {
		int pos = lower_bound(tailIdx.begin(), tailIdx.end(), a[i],
			[&](int idx, int val) { return a[idx] < val; }) - tailIdx.begin();

		if (pos > 0) parent[i] = tailIdx[pos - 1];

		if (pos == (int)tailIdx.size()) tailIdx.push_back(i);
		else tailIdx[pos] = i;
	}

	int len = tailIdx.size();
	vector<int> ans(len);
	int cur = tailIdx.back();
	for (int i = len - 1; i >= 0; i--) {
		ans[i] = a[cur];
		cur = parent[cur];
	}

	cout << len << '\n';
	for (int i = 0; i < len; i++) cout << ans[i] << ' ';

	return 0;
}
