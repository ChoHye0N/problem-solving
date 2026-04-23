#include <bits/stdc++.h>
using namespace std;

int main() {
    double w, h, n;
    cin >> w >> h >> n;

    double sum = 0.;

    for (int i = 1; i <= n / 2; i++) {
        sum += h * (1. - 2. / n * i);
    }

    cout << fixed << setprecision(7) << sum * 2;

    return 0;
}