#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;

    int chk = 0, other = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'C') chk++;
        else other++;
    }

    if (chk == 0) {
        cout << 0;
        return 0;
    }
    if (other == 0) {
        cout << chk;
        return 0;
    }

    cout << (chk + (other + 1) - 1) / (other + 1);

    return 0;
}