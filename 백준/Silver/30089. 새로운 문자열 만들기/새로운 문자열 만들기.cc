#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string str, rStr;
        cin >> str;

        rStr = str;
        reverse(rStr.begin(), rStr.end());

        int len = 0;
        for (int i = str.size(); i > 0; i--) {
            if (str.substr(str.size() - i) == rStr.substr(0, i)) {
                len = i;
                break;
            }
        }

        cout << str + rStr.substr(len) << '\n';
    }

    return 0;
}