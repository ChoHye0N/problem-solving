#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str, ans = "";
		cin >> str;

		set<char> setC(str.begin(), str.end());
		sort(str.begin(), str.end());

		if (setC.size() == 2 && str[0] == str[1] && str[2] == str[3]) ans = "Yes";
		else ans = "No";

		printf("#%d %s\n", t + 1, ans.c_str());
	}

	return 0;
}