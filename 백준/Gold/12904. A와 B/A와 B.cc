#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    while (t.size() > s.size()) {
        if (t.back() == 'A') {
            t.pop_back();
        }
        else if (t.back() == 'B') {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }

    cout << (s == t ? 1 : 0) << '\n';

    return 0;
}