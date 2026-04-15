#include <bits/stdc++.h>

using namespace std;

using llg = long long;

llg gcd(llg a, llg b) {
    return (b ? gcd(b, a % b) : a);
}

llg lcm(llg a, llg b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    llg num, den;
    vector<llg> a(n), b(n);

    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;

        int g = gcd(t1, t2);
        a[i] = t1 / g;
        b[i] = t2 / g;
    }

    den = 1;
    for (int i = 0; i < n; i++) {
        den = lcm(den, b[i]);
    }

    for (int i = 0; i < n; i++) {
        a[i] *= (den / b[i]);
    }

    num = a[0];
    for (int i = 1; i < n; i++) {
        num = gcd(num, a[i]);
    }

    int g = gcd(num, den);
    cout << (num / g) << ' ' << (den / g) << '\n';

    return 0;
}