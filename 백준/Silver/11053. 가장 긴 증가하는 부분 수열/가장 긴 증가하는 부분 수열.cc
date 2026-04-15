#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* LIS(Longest Increasing Subsequence) [O(N^2)] */
int lis(const vector<int>& arr, int size) {
	vector<int> dArr(size, 1);
	int maxLength = 0;

	for (int i = 1; i < size; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && dArr[i] < dArr[j] + 1)
				dArr[i] = dArr[j] + 1;
	
	for (int i = 0; i < size; i++)
		if (maxLength < dArr[i]) maxLength = dArr[i];

	return maxLength;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << lis(arr, n) << '\n';
}