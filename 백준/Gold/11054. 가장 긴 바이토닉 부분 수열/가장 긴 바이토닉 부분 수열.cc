#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* LBS(Longest Bitonic Subsequence) [O(N^2)] */
int lbs(const vector<int>& arr, int size) {
	int maxLength = 0;
    vector<int> lis(size, 1);
    vector<int> lds(size, 1);

	// LIS
	for (int i = 1; i < size; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	// LDS
	for (int i = size - 2; i >= 0; i--)
		for (int j = size - 1; j > i; j--)
			if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
				lds[i] = lds[j] + 1;
	
	for (int i = 0; i < size; i++) {
		maxLength = max(maxLength, lis[i] + lds[i] - 1);
	}

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

	cout << lbs(arr, n) << '\n';
}