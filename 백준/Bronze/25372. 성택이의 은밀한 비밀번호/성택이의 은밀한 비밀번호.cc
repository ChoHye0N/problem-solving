#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        cout << (str.size() >= 6 && str.size() <= 9 ? "yes\n" : "no\n");
    }

    return 0;
}