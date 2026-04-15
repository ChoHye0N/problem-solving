#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str;
    cin >> n >> str;

    int cnt = 1;
    bool ok = false;

    for (int i = 1; i < n; i++) {
        if (abs(str[i - 1] - str[i]) == 1) cnt++;
        else cnt = 1;
        
        if (cnt >= 5) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "YES" : "NO");

    return 0;
}