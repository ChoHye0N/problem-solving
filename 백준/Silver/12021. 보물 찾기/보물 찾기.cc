#include <iostream>
#include <iomanip>
#include <cmath>

using llg = long long;

using namespace std;

int main() {
    llg a, b;
    cin >> a >> b;

    double x0 = a, y0 = b;
    double x1 = a, y1 = b;
    const double EPSILON = 1e-9;

    for (int i = 0; i < 100000; i++) {
        x1 = (x0 + y0) / 2;
        y1 = 2 * (x0 * y0) / (x0 + y0);

        if (fabs(x1 - x0) < EPSILON && fabs(y1 - y0) < EPSILON) break;

        x0 = x1;
        y0 = y1;
    }

    cout << fixed << setprecision(6) << x1 << ' ' << y1 << '\n';

    return 0;
}