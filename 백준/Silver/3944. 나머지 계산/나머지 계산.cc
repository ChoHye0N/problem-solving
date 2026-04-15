#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int b;
        string d;
        cin >> b >> d;

        int ans = 0;
        for (int i = 0; i < d.size(); i++) {
            ans += ((d[d.size() - 1 - i]) - '0') % (b - 1);
        }

        cout << ans % (b - 1) << '\n';
    }

    return 0;
}