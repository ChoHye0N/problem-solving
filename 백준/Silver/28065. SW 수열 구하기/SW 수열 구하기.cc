#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a = n, b = 1;
    for (int i = 0; i < n; i++) {
        cout << (i % 2 == 0 ? b++ : a--) << ' ';
    }

    return 0;
}