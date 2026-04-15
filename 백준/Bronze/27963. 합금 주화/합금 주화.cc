#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, x;
    cin >> a >> b >> x;

    if (a < b) swap(a, b);

    double d = 100. / (x / a + (100 - x) / b);
    cout << fixed << setprecision(9) << d;

    return 0;
}