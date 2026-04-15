#include <bits/stdc++.h>
using namespace std;
using llg = long long;

llg comb(int n, int r) {
    if (r > n / 2) r = n - r;

    llg res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - i + 1) / i;
    }

    return res;
}

double p_p(double p) {
    int primes[] = { 2, 3, 5, 7, 11, 13, 17 };
    double res = 0;

    for (int i : primes) {
        res += comb(18, i) * pow(p, i) * pow(1 - p, 18 - i);
    }

    return res;
}

int main() {
    double a, b;
    cin >> a >> b;

    a /= 100, b /= 100;

    double ap = p_p(a), bp = p_p(b);

    printf("%.9f", ap + bp - (ap * bp));

    return 0;
}