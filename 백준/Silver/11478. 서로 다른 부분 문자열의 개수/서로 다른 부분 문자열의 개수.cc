#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = s.size();
	unordered_set<string> substrings;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			substrings.insert(s.substr(i, j - i));
		}
	}

	cout << substrings.size();

	return 0;
}
