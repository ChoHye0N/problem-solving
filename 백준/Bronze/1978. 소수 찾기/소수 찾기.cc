#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, count = 0;
	cin >> n;

	// O(N^2)
	for (int i = 0; i < n; i++) {
		int pn;
		cin >> pn;

		if (pn == 1) continue;
		else if (pn == 2) {
			count++;
			continue;
		}

		for (int j = 2; j < pn; j++) {
			if (pn % j == 0) break;
			if (j == pn - 1) count++;
		}
	}

	cout << count << '\n';

	return 0;
}