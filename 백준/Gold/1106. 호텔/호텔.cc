#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;

int main() {
    int c, n;
    cin >> c >> n;

    vector<pair<int, int>> arr(n);
    vector<int> dp(MAX, 0);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        arr[i] = { x, y };
    }

    for (int i = 0; i < n; i++) {
        int w = arr[i].first, v = arr[i].second;

        for (int j = w; j < MAX; j++) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < MAX; i++) {
        if (dp[i] >= c) {
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}