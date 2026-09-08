#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];

	sort(c.rbegin(), c.rend());

	long long total = 0;
	for (int i = 0; i < n; i++) {
		if (i % 3 != 2) total += c[i];
	}

	cout << total;

	return 0;
}
