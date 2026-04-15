#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << string(i, ' ');
        cout << string(n * 2 - 1 - (2 * i), '*') << '\n';
    }

    return 0;
}