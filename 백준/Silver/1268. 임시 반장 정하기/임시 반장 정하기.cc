#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(5));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<bool>> checked(n, vector<bool>(n, false));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[j][i] == arr[k][i]) {
					checked[j][k] = true;
					checked[k][j] = true;
				}
			}
		}
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			if (checked[i][j]) cnt++;
		}
		ans.push_back({ i + 1, cnt });
	}
	sort(ans.begin(), ans.end(), [](auto a, auto b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
		});

	cout << ans[0].first;

	return 0;
}