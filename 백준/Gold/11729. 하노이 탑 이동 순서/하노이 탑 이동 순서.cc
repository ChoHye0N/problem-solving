#include <bits/stdc++.h>
using namespace std;

void h_f(int n, int u, int v, int tmp) {
    if (n == 1) {
        cout << u << " " << v << '\n';
        return;
    }

    h_f(n - 1, u, tmp, v);
    cout << u << ' ' << v << '\n';
    h_f(n - 1, tmp, v, u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    cout << (1 << n) - 1 << '\n';
    h_f(n, 1, 3, 2);

    return 0;
}