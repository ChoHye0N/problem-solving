#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b, h;
    cin >> a >> b >> h;

    if (a == b) {
        cout << -1;
        return 0;
    }

    if (a > b) swap(a, b);

    double hs = (a * h) / (b - a), ht = hs + h;
    double r1 = a * a + hs * hs, r2 = b * b + ht * ht;

    printf("%.7f", (r2 - r1) * acos(-1));

    return 0;
}