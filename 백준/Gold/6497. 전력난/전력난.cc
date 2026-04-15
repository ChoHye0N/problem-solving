#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w;
};

struct DSU {
	vector<int> p, r;

	DSU(int n) : p(n + 1), r(n + 1, 0) {
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}
	}

	int find(int x) {
		if (p[x] == x) return x;
		return p[x] = find(p[x]);
	}

	bool unite(int a, int b) {
		a = find(a), b = find(b);

		if (a == b) return false;
		if (r[a] < r[b]) swap(a, b);

		p[b] = a;
		if (r[a] == r[b]) r[a]++;

		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = -1, m = -1;
	vector<int> ans;

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		int total = 0;
		vector<Edge> arr(m);

		for (int i = 0; i < m; i++) {
			cin >> arr[i].u >> arr[i].v >> arr[i].w;
			total += arr[i].w;
		}

		sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
			return a.w < b.w;
			});

		DSU dsu(n);
		int len = 0;

		for (auto& p : arr) {
			if (dsu.unite(p.u, p.v)) {
				len += p.w;
			}
		}

		ans.push_back(total - len);
	}

	for (int p : ans) {
		cout << p << '\n';
	}

	return 0;
}