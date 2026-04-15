#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string check[2] = {".omln", "owln."};

    vector<string> arr;
    for (int i = 0; i < 5; i++) {
        string str;
        getline(cin, str);

        arr.push_back(str);
    }

    for (int i = 0; i < arr[0].size(); i++) {
        string tmp = "";
        for (int j = 0; j < 5; j++) {
            tmp += arr[j][i];
        }
        for (int j = 0; j < 2; j++) {
            if (tmp == check[j]) {
                for (int k = 0; k < 5; k++) {
                    arr[k][i] = check[(j + 1) % 2][k];
                }
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}