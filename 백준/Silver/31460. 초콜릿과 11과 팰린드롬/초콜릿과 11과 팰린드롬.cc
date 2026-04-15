#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        else if (n % 2 == 0) {
            cout << string(n, '1') << '\n';
        }
        else {
            string str(n, '2');
            str[0] = '1', str[n - 1] = '1';
            cout << str << '\n';
        }
    }

    return 0;
}