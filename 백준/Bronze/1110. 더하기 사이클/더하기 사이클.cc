#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    if (n.size() < 2) n = '0' + n;

    string strN = n;
    int ans = 0;

    while (true) {
        int n1 = n[0] - '0', n2 = n[1] - '0';
        int nn1 = (n1 + n2) % 10;

        n = string{ char(n2 + '0'),char(nn1 + '0') };
        ans++;

        if (n == strN) break;
    }

    cout << ans;

    return 0;
}