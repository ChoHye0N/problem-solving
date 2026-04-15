#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> y >> x;

        if (y < 12 || x < 4) {
            cout << -1 << '\n';
            continue;
        }

        cout << 11 * x + 4 << '\n';
    }

    return 0;
}