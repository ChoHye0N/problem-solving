#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    map<char, int> arr;
    for (char c : str) {
        arr[tolower(c)]++;

    }

    char ans;
    int maxN = 0, flag = 0;

    for (auto& p : arr) {
        if (maxN < p.second) {
            maxN = p.second;
            ans = p.first;
            flag = 0;
        }
        else if (maxN == p.second) {
            flag = 1;
        }
    }
    if (flag) ans = '?';

    cout << (char)toupper(ans);

    return 0;
}