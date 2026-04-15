#include <bits/stdc++.h>
using namespace std;

using llg = long long;
const int MOD = 1e9 + 7;

llg f_pow(llg a, llg x) {
    llg res = 1;
    a %= MOD;

    while (x > 0) {
        if (x & 1) res = (res * a) % MOD;

        a = (a * a) % MOD;
        x >>= 1;
    }

    return res;
}

int main() {
    llg a, x;
    cin >> a >> x;

    cout << f_pow(a, x);

    return 0;
}