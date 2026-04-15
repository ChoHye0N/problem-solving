#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int maxD = 0;

            maxD = max(maxD, abs(i - 1) + abs(j - 1));
            maxD = max(maxD, abs(i - 1) + abs(j - m));
            maxD = max(maxD, abs(i - n) + abs(j - 1));
            maxD = max(maxD, abs(i - n) + abs(j - m));

            if (maxD <= d - 1) {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}