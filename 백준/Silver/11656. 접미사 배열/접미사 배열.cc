#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    vector<string> arr;
    for (int i = 0; i < str.size(); i++) {
        arr.push_back(str.substr(str.size() - 1 - i, i + 1));
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}