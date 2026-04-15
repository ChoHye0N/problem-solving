#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (n % 2024 == 0 && n <= 100000 ? "Yes" : "No");

    return 0;
}