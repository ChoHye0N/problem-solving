#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> arr, cArr;

void combination(int n, int m, int index, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << cArr[i] << " ";
		}
		cout << '\n';
		return;
	}

	// Combination
	for (int i = index; i < n; i++) {
		cArr[depth] = arr[i];
		// But it can choose the same number
		combination(n, m, i, depth + 1);
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr.push_back(i + 1);
	}

	cArr.resize(m);
	combination(n, m, 0, 0);

	return 0;

}