#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int d = ceil((sqrt(1 + 8 * n) - 1) / 2);
    int prev = (d - 1) * d / 2, pos = n - prev;

    int a, b;
    if (d % 2 == 1) {
        a = d - pos + 1;
        b = pos;
    }
    else {
        a = pos;
        b = d - pos + 1;
    }

    cout << a << '/' << b;

    return 0;
}