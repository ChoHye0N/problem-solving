#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int h1 = -1, h2 = -1, m = 0, ra1 = 0, ra2 = 0, rl1 = 0, rl2 = 0;
    bool flag = false;

    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 1; j <= n; j++) {
            if (!flag && tmp[j - 1] == '*') {
                h1 = j, h2 = i + 1;
                flag = true;
            }

            else if (flag && tmp[j - 1] == '*') {
                if (i == h2) {
                    if (j < h1) ra1++;
                    else if (j > h1) ra2++;
                }
                else if (i > h2) {
                    if (j == h1) m++;
                    else {
                        if (j == h1 - 1) rl1++;
                        else if (j == h1 + 1) rl2++;
                    }
                }
            }
        }
    }

    cout << h2 << ' ' << h1 << '\n';
    cout << ra1 << ' ' << ra2 << ' ' << m << ' ' << rl1 << ' ' << rl2;

    return 0;
}