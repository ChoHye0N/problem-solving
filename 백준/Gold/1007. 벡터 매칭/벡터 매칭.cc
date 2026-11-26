#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        long long res = LLONG_MAX;

        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) != n / 2) continue;

            long long sx = 0, sy = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sx += points[i].x;
                    sy += points[i].y;
                }
                else {
                    sx -= points[i].x;
                    sy -= points[i].y;
                }
            }
            res = min(res, sx * sx + sy * sy);
        }

        cout << fixed << setprecision(12) << sqrt((double)res) << '\n';
    }

    return 0;
}