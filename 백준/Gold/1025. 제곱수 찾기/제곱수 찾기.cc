#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_square(ll num) {
    if (num < 0) return false;

    ll sq = sqrtl(num);
    while ((sq + 1) * (sq + 1) <= num) sq++;
    while (sq * sq > num) sq--;

    return sq * sq == num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string arr[10];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll res = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dr = -n; dr < n; dr++) {
                for (int dc = -m; dc < m; dc++) {
                    if (dr == 0 && dc == 0) continue;

                    int y = i, x = j;
                    ll sum = 0;

                    while (0 <= y && y < n && 0 <= x && x < m) {
                        sum = sum * 10 + (arr[y][x] - '0');
                        if (is_square(sum)) res = max(res, sum);

                        y += dr, x += dc;
                    }
                }
            }
        }
    }

    cout << res;

    return 0;
}