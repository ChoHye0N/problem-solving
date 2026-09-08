#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;

struct Mat {
	ll a[2][2];
};

Mat mul(const Mat& x, const Mat& y) {
	Mat r;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			r.a[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				r.a[i][j] = (r.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
			}
		}
	}
	return r;
}

Mat power(Mat base, ll exp) {
	Mat res = { {{1, 0}, {0, 1}} };
	while (exp > 0) {
		if (exp & 1) res = mul(res, base);
		base = mul(base, base);
		exp >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	Mat base = { {{1, 1}, {1, 0}} };
	Mat res = power(base, n - 1);

	cout << res.a[0][0];

	return 0;
}
