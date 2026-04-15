#include <bits/stdc++.h>
using namespace std;

long long fact(long long n) {
    if (n == 1) return 1;

    return n * fact(n - 1);
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << fact(n) / (fact(a) * fact(b) * fact(c));

    return 0;
}