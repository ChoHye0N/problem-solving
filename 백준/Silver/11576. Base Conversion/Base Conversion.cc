#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, m;
	cin >> a >> b >> m;

	long long value = 0;
	for (int i = 0; i < m; i++) {
		int digit;
		cin >> digit;
		value = value * a + digit;
	}

	vector<int> result;
	if (value == 0) result.push_back(0);
	while (value > 0) {
		result.push_back(value % b);
		value /= b;
	}

	reverse(result.begin(), result.end());

	for (int i = 0; i < (int)result.size(); i++) {
		cout << result[i];
		if (i != (int)result.size() - 1) cout << ' ';
	}

	return 0;
}
