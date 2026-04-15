#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    int n, op = 1;
    cin >> n;

    vector<llg> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a.size() > 2) {
        llg curr = a[1] - a[0];
        for (int i = 2; i < n; i++) {
            if (a[i] - a[i - 1] != curr) {
                op = 0;
                break;
            }
        }
    }

    if (op) {
        cout << "YES\n";

        for (int i = 0; i < n; i++) {
            cout << a[i] * 2 << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; i++) {
            cout << -a[i] << ' ';
        }
    }
    else cout << "NO";

    return 0;
}