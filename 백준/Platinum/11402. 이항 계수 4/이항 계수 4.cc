#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll M;
vector<ll> fact;

ll modpow(ll base, ll exp, ll mod) {
	ll res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp & 1) res = res * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

ll small_comb(ll n, ll k) {
	if (k < 0 || k > n) return 0;
	return fact[n] * modpow(fact[k], M - 2, M) % M * modpow(fact[n - k], M - 2, M) % M;
}

ll lucas(ll n, ll k) {
	if (k == 0) return 1;

	ll ni = n % M, ki = k % M;
	if (ki > ni) return 0;

	return small_comb(ni, ki) * lucas(n / M, k / M) % M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k >> M;

	fact.assign(M, 1);
	for (ll i = 1; i < M; i++) fact[i] = fact[i - 1] * i % M;

	cout << lucas(n, k);

	return 0;
}
