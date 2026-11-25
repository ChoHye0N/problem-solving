#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n != 1 && ((n + 2) & (n + 1))) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i < n + 1; i++){
        cout << i << ' ';
    }

    return 0;
}