#include <bits/stdc++.h>
using namespace std;

int main() {
    bool flag = false;

    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;

        if (str.find("FBI") != string::npos) {
            cout << i + 1 << ' ';
            flag = true;
        }
    }

    if (!flag) cout << "HE GOT AWAY!";

    return 0;
}