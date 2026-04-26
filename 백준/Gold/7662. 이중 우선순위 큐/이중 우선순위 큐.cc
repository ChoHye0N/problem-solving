#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;

		multiset<int> dpq;

		while (k--) {
			char cmd;
			cin >> cmd;

			if (cmd == 'I') {
				int n;
				cin >> n;

				dpq.insert(n);
			}
			else if (cmd == 'D') {
				int n;
				cin >> n;

				if (n == 1 && !dpq.empty()) {
					dpq.erase(prev(dpq.end()));
				}
				else if (n == -1 && !dpq.empty()) {
					dpq.erase(dpq.begin());
				}
			}
		}

		if (!dpq.empty()) {
			cout << *prev(dpq.end()) << ' ' << *dpq.begin() << '\n';
		}
		else cout << "EMPTY\n";
	}

	return 0;
}