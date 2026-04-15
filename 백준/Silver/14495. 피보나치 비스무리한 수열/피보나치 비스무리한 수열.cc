#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    int n;
    cin >> n;

    vector<llg> dp(n + 1, 1);
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }

    cout << dp[n];

    return 0;
}