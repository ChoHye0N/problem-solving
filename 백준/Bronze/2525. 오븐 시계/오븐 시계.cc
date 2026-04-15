#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << (a + ((c + b) / 60)) % 24 << ' ' << (b + c % 60) % 60;

    return 0;
}