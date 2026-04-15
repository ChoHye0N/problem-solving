#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int a = 0, b = 0;
    for (char c : str) {
        c == '0' ? a++ : b++;
    }
    a /= 2, b /= 2;

    string ans = "";
    vector<bool> check(str.size(), false);

    int ra = 0;
    for (int i = str.size() - 1; i >= 0 && ra < a; i--) {
        if (str[i] == '0') {
            check[i] = true;
            ra++;
        }
    }

    int rb = 0;
    for (int i = 0; i < str.size() && rb < b; i++) {
        if (str[i] == '1') {
            check[i] = true;
            rb++;
        }
    }

    for (int i = 0; i < str.size(); i++) {
        if (!check[i]) cout << str[i];
    }

    return 0;
}