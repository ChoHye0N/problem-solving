#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp % 2 != i % 2) {
            ans = 0;
            break;
        }
    }

    cout << (ans ? "YES" : "NO");

    return 0;
}