#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    queue<int> q;

    while (t--) {
        string op;
        cin >> op;

        if (op == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (op == "pop") {
            if (q.size() == 0) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            };
        }
        else if (op == "size") {
            cout << q.size() << '\n';
        }
        else if (op == "empty") {
            cout << q.empty() << '\n';
        }
        else if (op == "front") {
            cout << (!q.empty() ? q.front() : -1) << '\n';
        }
        else if (op == "back") {
            cout << (!q.empty() ? q.back() : -1) << '\n';
        }
    }

    return 0;
}