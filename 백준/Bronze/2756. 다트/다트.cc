#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n = 0, m = 0;

        for (int i = 0; i < 6; i++) {
            double x, y, dist;
            cin >> x >> y;

            dist = sqrt(x * x + y * y);

            if (i < 3) {
                if (dist <= 3) n += 100;
                else if (dist <= 6) n += 80;
                else if (dist <= 9) n += 60;
                else if (dist <= 12) n += 40;
                else if (dist <= 15) n += 20;
            }
            else {
                if (dist <= 3) m += 100;
                else if (dist <= 6) m += 80;
                else if (dist <= 9) m += 60;
                else if (dist <= 12) m += 40;
                else if (dist <= 15) m += 20;
            }
        }

        if (n > m) printf("SCORE: %d to %d, PLAYER 1 WINS.\n", n, m);
        else if (n < m) printf("SCORE: %d to %d, PLAYER 2 WINS.\n", n, m);
        else printf("SCORE: %d to %d, TIE.\n", n, m);
    }

    return 0;
}