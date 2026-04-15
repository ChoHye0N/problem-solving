#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;

    while (cin >> s >> t) {
        int sIdx = 0;

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[sIdx])
                sIdx++;
            if (sIdx == s.size())
                break;
        }

        if (sIdx == s.size())
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }

    return 0;
}