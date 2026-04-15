#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, max = -1000001, min = 1000001;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}

	cout << min << " " << max << '\n';

	return 0;
}