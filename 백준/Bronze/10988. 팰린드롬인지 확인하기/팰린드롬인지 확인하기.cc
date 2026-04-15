#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1;

    str2 = string(str1.rbegin(), str1.rend());

    cout << (str1 == str2 ? 1 : 0);

    return 0;
}