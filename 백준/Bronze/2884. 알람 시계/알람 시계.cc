#include <iostream>

using namespace std;

int main() {
    int h, m;
    cin >> h >> m;

    m -= 45;
    if (m < 0) {
        m += 60;
        h = (h == 0) ? 23 : h - 1;
    }

    cout << h << ' ' << m << '\n';
    return 0;
}