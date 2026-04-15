#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    string alpha[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        for (string s : alpha) {
            if (str.substr(i, 2) == s) {
                i++;
                break;
            }
            else if (str.substr(i, 3) == s) {
                i += 2;
                break;
            }
        }
        ans++;
    }

    cout << ans;

    return 0;
}