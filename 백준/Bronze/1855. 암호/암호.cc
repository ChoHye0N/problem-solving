#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    int r = str.size() / n;
    string ans = "";

    for (int i = 1; i < r; i += 2) {
        reverse(str.begin() + i * n, str.begin() + i * n + n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            ans += str[j * n + i];
        }
    }

    cout << ans;

    return 0;
}