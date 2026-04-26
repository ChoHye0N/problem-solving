#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string str;
	cin >> n >> str;

	int rb = 0, ld = 0;
	for (char c : str) {
		if (c == 'B') rb++;
	}

	int minN = rb;
	for (char c : str) {
		if (c == 'B') rb--;
		else ld++;

		minN = min(minN, rb + ld);
	}

	cout << minN;

	return 0;
}