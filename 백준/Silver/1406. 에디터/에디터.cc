#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int n;
    cin >> str >> n;

    list<int> lst;
    for (int i = 0; i < str.size(); i++) {
        lst.push_back(str[i]);
    }

    auto it = lst.end();
    while (n--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L' && it != lst.begin()) it--;
        else if (cmd == 'D' && it != lst.end()) it++;
        else if (cmd == 'B' && it != lst.begin()) {
            it = lst.erase(--it);
        }
        else if (cmd == 'P') {
            char c;
            cin >> c;

            lst.emplace(it, c);
        }
    }

    for (char c : lst) {
        cout << c;
    }

    return 0;
}