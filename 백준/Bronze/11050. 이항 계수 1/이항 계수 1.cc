#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int c = 1;
	for (int i = 1; i <= n; i++) c *= i;
	for (int i = 1; i <= k; i++)c /= i;
	for (int i = 1; i <= n - k; i++)c /= i;

	cout << c << '\n';

	return 0;
}