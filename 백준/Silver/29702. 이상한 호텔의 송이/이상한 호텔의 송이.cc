#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;


    while (t--) {
        llg n, f = 0, r;
        cin >> n;

        llg tmp = n;
        while (tmp) {
            tmp /= 2;
            f++;
        }
        r = n - (1LL << (f - 1)) + 1;

        for (int i = 0; i < f; i++) {
            string tmp = to_string(f - i), sR = to_string(r);
            
            while (sR.size() < 18) {
                sR = "0" + sR;
            }

            tmp += sR;

            cout << tmp << '\n';
            r = (r + 1) / 2;
        }
    }

    return 0;
}