#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int k;
	cin >> k;

	if (k == 2) {
		for (int i = 0; i < n; i++) {
			reverse(arr[i].begin(), arr[i].end());
		}
	}
	else if (k == 3) {
		reverse(arr.begin(), arr.end());
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
