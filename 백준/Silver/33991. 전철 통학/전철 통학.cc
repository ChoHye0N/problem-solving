#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int q;
    cin >> q;

    while (q--) {
        int x, y, t1, t2, t3;
        cin >> x >> y >> t1 >> t2 >> t3;

        llg d1 = abs(x - x1) + abs(y - y1), d2 = abs(x - x2) + abs(y - y2),
            d3 = abs(x - x3) + abs(y - y3);

        llg et1 = ((d1 + t1 - 1) / t1) * t1, et2 = ((d2 + t2 - 1) / t2) * t2,
            et3 = ((d3 + t3 - 1) / t3) * t3;

        cout << min({ et1, et2, et3 }) << '\n';
    }

    return 0;
}