#include <bits/stdc++.h>
using namespace std;

int ans, n, k;
vector<int> apple;

void dfs(vector<vector<int>>& arr, vector<int>& v, int ap, int d) {
	ans = max(ans, ap);

	if (d == k) return;

	for (int i = 0; i < v.size(); i++) {
		int node = v[i];
		vector<int> nv;

		for (int j = i + 1; j < v.size(); j++) {
			nv.push_back(v[j]);
		}
		for (int c : arr[node]) {
			nv.push_back(c);
		}

		dfs(arr, nv, ap + apple[node], d + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	vector<vector<int>> arr(n);
	vector<int> v;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		arr[u].push_back(v);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		apple.push_back(tmp);
	}

	for (int c : arr[0]) {
		v.push_back(c);
	}

	dfs(arr, v, apple[0], 1);

	cout << ans;

	return 0;
}