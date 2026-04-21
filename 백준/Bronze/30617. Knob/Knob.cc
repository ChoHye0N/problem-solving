#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int ans = 0, p1 = 0, p2 = 0;
    cin >> p1 >> p2;

    if (p1 == p2 && p1 != 0) ans++;
    t--;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (p1 == a && a != 0) ans++;
        if (p2 == b && b != 0) ans++;
        if (a == b && a != 0) ans++;

        p1 = a, p2 = b;
    }

    cout << ans;

    return 0;
}