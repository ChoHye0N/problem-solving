#include <iostream>
#include <vector>
#include <string>

using namespace std;

int is_consonant(char c) {
    char vowel[] = "AEIOU";

    for (char w : vowel)
        if (c == w)
            return 0;
    return 1;
}

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<char> result;

    for (int i = 0; i < n; i++) {
        if (result.size() == m - 3) {
            if (s[i] == 'A') {
                result.push_back(s[i]);
            }
        }
        else if (result.size() == m - 2) {
            if (s[i] == 'A') {
                result.push_back(s[i]);
            }
        }
        else if (result.size() == m - 1) {
            if (is_consonant(s[i])) {
                result.push_back(s[i]);
            }
        }
        else if (result.size() < m - 3) {
            result.push_back(s[i]);
        }

        if (result.size() == m) {
            break;
        }
    }

    if (result.size() == m && result[m - 1] != 'A' && is_consonant(result[m - 1])) {
        cout << "YES" << '\n';
        for (char c : result)
            cout << c;
        cout << '\n';
    }
    else
        cout << "NO" << '\n';

    return 0;
}