#include <bits/stdc++.h>
using namespace std;

using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    llg n;
    int l;
    cin >> n >> l;

    for (int i = l; i <= 100;i++) {
        llg a = 2 * n - i * (i - 1);
        int b = 2 * i;

        if (a >= 0 && a % b == 0) {
            for (int j = 0; j < i; j++) {
                cout << a / b + j << ' ';
            }
            return 0;
        }
    }

    cout << -1;

    return 0;
}