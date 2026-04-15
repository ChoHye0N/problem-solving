#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int MOD = 1e4 + 7;

llg ncr(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;

    vector<llg> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0 ; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }

    return dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << ncr(n, k);

    return 0;
}