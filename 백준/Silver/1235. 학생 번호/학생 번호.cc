#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int len = arr[0].size(), ans = len;

    for (int i = 1; i <= len; i++) {
        set<string> check;

        for (int j = 0; j < n; j++) {
            check.insert(arr[j].substr(len - i, i));
        }
        if (check.size() == n) ans = min(ans, i);
    }

    cout << ans;

    return 0;
}