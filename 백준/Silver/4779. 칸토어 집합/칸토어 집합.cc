#include <bits/stdc++.h>
using namespace std;

void f(string& str, int s, int e) {
    if (e - s < 2) return;

    int t = (e - s) / 3;

    for (int i = s + t; i < s + 2 * t; i++) {
        str[i] = ' ';
    }

    f(str, s, s + t);
    f(str, s + 2 * t, e);
}

int main() {
    int n;

    while (cin >> n) {
        string str(pow(3, n), '-');
        f(str, 0, pow(3, n));

        cout << str << '\n';
    }

    return 0;
}