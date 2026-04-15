#include <bits/stdc++.h>
using namespace std;

int str2dgt(string& s) {
    int res = 0;

    for (char c : s) {
        if (c >= '0' && c <= '9') res += c - '0';
    }

    return res;
}

int comp(string& a, string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    else if (str2dgt(a) != str2dgt(b)) return str2dgt(a) < str2dgt(b);
    else return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), comp);

    for (string str : arr) {
        cout << str << '\n';
    }

    return 0;
}