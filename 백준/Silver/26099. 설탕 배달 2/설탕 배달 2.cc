#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    for (long long i = n / 5; i >= 0; --i) {
        long long remainder = n - (i * 5);
        if (remainder % 3 == 0) {
            cout << i + (remainder / 3) << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}