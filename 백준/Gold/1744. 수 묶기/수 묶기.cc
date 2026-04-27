#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int zero = 0, one = 0;
	vector<int> minus, plus;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		if (tmp > 1) plus.push_back(tmp);
		else if (tmp < 0) minus.push_back(tmp);
		else if (tmp == 1) one++;
		else zero++;
	}

	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end());

	long long sum = 0;
	for (int i = 0; i < (int)minus.size() - 1; i += 2) {
		sum += minus[i] * minus[i + 1];
	}
	for (int i = (int)plus.size() - 1; i > 0; i -= 2) {
		sum += plus[i] * plus[i - 1];
	}

	if (!minus.empty() && minus.size() % 2 != 0 && zero == 0) {
		sum += minus[minus.size() - 1];
	}
	if (!plus.empty() && plus.size() % 2 != 0) {
		sum += plus[0];
	}
	if (one > 0) sum += one;

	cout << sum;

	return 0;
}