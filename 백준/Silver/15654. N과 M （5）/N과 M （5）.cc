#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr, pArr;
bool used[8];

void permutation(int n, int m, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << pArr[i] << " ";
		}
		cout << '\n';
		return;
	}

	// Permutation
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			used[i] = true;
			pArr[depth] = arr[i];
			permutation(n, m, depth + 1);
			used[i] = false;
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	pArr.resize(m);
	permutation(n, m, 0);

	return 0;
}