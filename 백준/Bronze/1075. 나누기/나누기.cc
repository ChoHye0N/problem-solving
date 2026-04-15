#include <iostream>

using namespace std;

int main() {
    int n, f;
    cin >> n >> f;

    int base = (n / 100) * 100;
    int ans = (base % f == 0) ? 0 : (f - base % f);

    if (ans < 10) {
        cout << '0' << ans << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}