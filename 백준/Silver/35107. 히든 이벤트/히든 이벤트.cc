#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= k; i++) {
        double ans = 1.;

        for (int j = 0; j < i; j++) {
            ans *= (double)(n - m - j) / (n - j);
        }
        
        cout << fixed << setprecision(10) << 1. - ans << '\n';
    }

    return 0;
}