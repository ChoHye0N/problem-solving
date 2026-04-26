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

		priority_queue<int> maxPq;
		priority_queue<int, vector<int>, greater<>> minPq;
		unordered_map<int, int> count;

		while (k--) {
			char cmd;
			cin >> cmd;

			if (cmd == 'I') {
				int n;
				cin >> n;

				maxPq.push(n), minPq.push(n);
				count[n]++;
			}
			else if (cmd == 'D') {
				int n;
				cin >> n;

				if (n == 1) {
					while (!maxPq.empty() && count[maxPq.top()] == 0) {
						maxPq.pop();
					}
					if (!maxPq.empty()) {
						count[maxPq.top()]--;
						maxPq.pop();
					}
				}
				else if (n == -1) {
					while (!minPq.empty() && count[minPq.top()] == 0) {
						minPq.pop();
					}
					if (!minPq.empty()) {
						count[minPq.top()]--;
						minPq.pop();
					}
				}
			}
		}

		while (!maxPq.empty() && count[maxPq.top()] == 0) maxPq.pop();
		while (!minPq.empty() && count[minPq.top()] == 0) minPq.pop();

		if (!maxPq.empty()) {
			cout << maxPq.top() << ' ' << minPq.top() << '\n';
		}
		else cout << "EMPTY\n";
	}

	return 0;
}