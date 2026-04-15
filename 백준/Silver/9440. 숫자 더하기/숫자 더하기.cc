#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        string s1 = "", s2 = "";
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                s1 += to_string(arr[i]);
                arr.erase(arr.begin() + i);
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                s2 += to_string(arr[i]);
                arr.erase(arr.begin() + i);
                break;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) s1 += to_string(arr[i]);
            else s2 += to_string(arr[i]);
        }

        cout << stoll(s1) + stoll(s2) << "\n";
    }

    return 0;
}