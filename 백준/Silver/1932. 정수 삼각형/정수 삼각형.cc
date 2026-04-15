#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++) {
		vector<int> tmpArr;

		for (int j = 0; j <= i; j++) {
			int tmp;
			cin >> tmp;

			tmpArr.push_back(tmp);
		}

		arr[i] = tmpArr;
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = arr[i - 1][j - 1] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	cout << *max_element(dp[n].begin(), dp[n].end());

	return 0;
}