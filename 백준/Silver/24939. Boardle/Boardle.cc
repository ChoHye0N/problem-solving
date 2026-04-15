#include <iostream>
#include <algorithm>

using llg = long long;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    llg n, m, q;
    cin >> n >> m >> q;

    llg x_min = 1, x_max = n;
    llg y_min = 1, y_max = m;

    for (int i = 0; i < q; i++) {
        llg x, y, pos;
        cin >> x >> y >> pos;

        // 각 위치에 대한 모든 조건 분기를 사용함
        if (pos == 1) {
            x_min = max(x_min, x + 1);
            y_min = y_max = y;
        }
        else if (pos == 2) {
            x_max = min(x_max, x - 1);
            y_min = y_max = y;
        }
        else if (pos == 3) {
            y_max = min(y_max, y - 1);
            x_min = x_max = x;
        }
        else if (pos == 4) {
            y_min = max(y_min, y + 1);
            x_min = x_max = x;
        }
        else if (pos == 5) {
            x_min = max(x_min, x + 1);
            y_min = max(y_min, y + 1);
        }
        else if (pos == 6) {
            x_max = min(x_max, x - 1);
            y_min = max(y_min, y + 1);
        }
        else if (pos == 7) {
            x_min = max(x_min, x + 1);
            y_max = min(y_max, y - 1);
        }
        else if (pos == 8) {
            x_max = min(x_max, x - 1);
            y_max = min(y_max, y - 1);
        }
        else {
            x_min = x_max = x;
            y_min = y_max = y;
        }
    }

    cout << (x_max - x_min + 1) * (y_max - y_min + 1) << "\n";

    return 0;
}