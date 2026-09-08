#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int r, int c) {
	if (n == 0) return 0;

	int half = 1 << (n - 1);
	int quadrant = (r >= half ? 2 : 0) + (c >= half ? 1 : 0);

	long long area = (long long)half * half;

	return area * quadrant + solve(n - 1, r % half, c % half);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, r, c;
	cin >> n >> r >> c;

	cout << solve(n, r, c);

	return 0;
}
