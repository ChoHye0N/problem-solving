#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "UOS";
    unsigned int n;
    cin >> n;

    cout << str[(n - 1) % 3];

    return 0;
}