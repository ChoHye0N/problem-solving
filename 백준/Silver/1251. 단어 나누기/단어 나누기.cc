#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    vector<string> arr;
    for (int i = 1; i < str.size() - 1; i++) {
        for (int j = i + 1; j < str.size(); j++) {
            string tmp = str;

            reverse(tmp.begin(), tmp.begin() + i);
            reverse(tmp.begin() + i, tmp.begin() + j);
            reverse(tmp.begin() + j, tmp.end());

            arr.push_back(tmp);
        }
    }

    sort(arr.begin(), arr.end());

    cout << arr[0];

    return 0;
}