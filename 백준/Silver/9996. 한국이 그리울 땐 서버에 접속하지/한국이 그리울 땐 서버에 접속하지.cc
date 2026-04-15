#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<string> check = { "", "" };
    int idx = 0;
    for (int i = 0; i < str.size(); i++) {
        char tmp = str[i];

        if (tmp == '*') idx++;
        else check[idx].push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        idx = 0;

        if (check[0].size() + check[1].size() > arr[i].size()) {
            cout << "NE" << '\n';
            continue;
        }

        if (check[idx] != arr[i].substr(0, check[idx].size()) && check[idx] != "") {
            cout << "NE" << '\n';
            continue;
        }
        idx++;
        if (check[idx] != arr[i].substr(arr[i].size() - check[idx].size(), check[idx].size()) && check[idx] != "") {
            cout << "NE" << '\n';
            continue;
        }

        cout << "DA" << '\n';

    }

    return 0;
}