#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int r, ans = 0;
    cin >> r;

    for (int i = 0; i < n; i++) {
        if (arr[i] == r) ans++;
    }

    cout << ans;

    return 0;
}