#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cout << ' ';
        }
        for (int j = i; j < n * 2 - i + 1; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = i - 1; j > 0; j--) {
            cout << ' ';
        }
        for (int j = n * 2 - i; j >= i; j--) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}