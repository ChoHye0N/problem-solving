#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string license;
        cin >> license;

        int first = (license[0] - 'A') * 26 * 26 + (license[1] - 'A') * 26 + (license[2] - 'A');
        int second = stoi(license.substr(4, 4));

        if (abs(first - second) <= 100)
            cout << "nice" << '\n';
        else
            cout << "not nice" << '\n';
    }

    return 0;
}