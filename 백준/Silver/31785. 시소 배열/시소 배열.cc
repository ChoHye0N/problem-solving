#include <bits/stdc++.h>
using namespace std;

using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    deque<int> dq;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;

            dq.push_back(x);
        }
        else if (op == 2) {
            int n = dq.size();
            llg fS = 0, bS = 0;

            for (int i = 0; i < n / 2; i++) {
                fS += dq[i];
            }
            for (int i = n / 2; i < n; i++) {
                bS += dq[i];
            }

            if (fS <= bS) {
                cout << fS << '\n';
                for (int i = 0; i < n / 2; i++) {
                    dq.pop_front();
                }
            }
            else {
                cout << bS << '\n';
                for (int i = 0; i < n - n / 2; i++) {
                    dq.pop_back();
                }
            }
        }
    }

    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i] << ' ';
    }

    return 0;
}