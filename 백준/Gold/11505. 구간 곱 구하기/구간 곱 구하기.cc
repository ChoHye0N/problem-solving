#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;
int n;
vector<ll> tree;
vector<ll> arr;

ll build(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	ll left = build(node * 2, start, mid);
	ll right = build(node * 2 + 1, mid + 1, end);

	return tree[node] = (left * right) % MOD;
}

void update(int node, int start, int end, int idx, ll val) {
	if (idx < start || idx > end) return;

	if (start == end) {
		tree[node] = val;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);

	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

ll query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) *
		query(node * 2 + 1, mid + 1, end, left, right)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, k;
	cin >> n >> m >> k;

	arr.resize(n + 1);
	tree.resize(4 * (n + 1));

	for (int i = 1; i <= n; i++) cin >> arr[i];

	build(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(1, 1, n, (int)b, c);
		}
		else {
			cout << query(1, 1, n, (int)b, (int)c) << '\n';
		}
	}

	return 0;
}
