#include <iostream>

using namespace std;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y) {
    return (x / gcd(x, y)) * y;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n' << lcm(a, b) << '\n';

    return 0;
}