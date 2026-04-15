#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    vector<int> arr;
    for (int i = 0; i < str.size(); i++) {
        string tmp = "";

        while (str[i] != ',' && i < str.size()) {
            tmp += str[i++];
        }

        arr.push_back(stoi(tmp));
    }

    for (int i = 0; i < k; i++) {
        vector<int> tmp;

        for (int j = 1; j < arr.size(); j++) {
            tmp.push_back(arr[j] - arr[j - 1]);
        }
        arr = tmp;
    }

    for (int i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << ',';
    }
    cout << arr[arr.size() - 1];

    return 0;
}