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

    int t;
    cin >> t;

    while (t--) {
        llg a, b;
        cin >> a >> b;

        cout << lcm(a, b) << '\n';
    }

    return 0;
}