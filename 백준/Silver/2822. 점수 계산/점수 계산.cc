#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> arr(8, vector<int> (2));
    int sum = 0, ans[5] = {};
    
    for (int i = 1; i <= 8; i++) {
        int n;
        cin >> n;

        arr[i - 1][0] = i;
        arr[i - 1][1] = n;
    }
    sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
        return a[1] > b[1];
        });

    for (int i = 0; i < 5; i++) {
        ans[i] = arr[i][0];
        sum += arr[i][1];
    }
    sort(ans, ans + 5);

    cout << sum << '\n';
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}