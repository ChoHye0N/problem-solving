#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    vector<int> arr(26, 0);
    for (char c : str) {
        arr[c - 'a']++;
    }

    for (int n : arr) {
        cout << n << ' ';
    }

    return 0;
}