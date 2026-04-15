#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    double a = (d1 + d2 - d3) / 2.0;
    double b = (d1 + d3 - d2) / 2.0;
    double c = (d2 + d3 - d1) / 2.0;

    if (a <= 0 || b <= 0 || c <= 0)
        cout << -1 << '\n';

    else {
        cout << 1 << '\n';
        cout << fixed << setprecision(1) << a << " " << b << " " << c << '\n';
    }

    return 0;
}