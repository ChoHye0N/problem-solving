#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0, x, y;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;

            if (ans <= tmp) {
                ans = tmp;
                y = i, x = j;
            }
        }
    }

    cout << ans << '\n' << y + 1 << ' ' << x + 1;

    return 0;
}