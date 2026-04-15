#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string strNN = to_string(n * n), strN = to_string(n);

        if (strNN.substr(strNN.size() - strN.size(), strN.size()) == strN) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }

    return 0;
}