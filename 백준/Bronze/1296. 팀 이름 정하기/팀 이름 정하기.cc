#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string name;
    cin >> name;

    vector<int> arr(4, 0);
    for (char c : name) {
        if (c == 'L') arr[0]++;
        else if (c == 'O') arr[1]++;
        else if (c == 'V') arr[2]++;
        else if (c == 'E') arr[3]++;
    }

    int n;
    cin >> n;

    map<string, int> mrr;
    while (n--) {
        string str;
        cin >> str;

        vector<int> brr = { arr[0], arr[1], arr[2], arr[3] };
        for (char c : str) {
            if (c == 'L') brr[0]++;
            else if (c == 'O') brr[1]++;
            else if (c == 'V') brr[2]++;
            else if (c == 'E') brr[3]++;
        }

        int sum = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                sum *= brr[i] + brr[j];
            }
        }
        mrr[str] = sum % 100;
    }

    vector<pair<string, int>> ans(mrr.begin(), mrr.end());
    sort(ans.begin(), ans.end(), [](auto& a, auto& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
        });

    cout << ans[0].first;

    return 0;
}