#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> flowers(n), items(m);
    for (int i = 0; i < n; i++){
        cin >> flowers[i];
    }
    for (int i = 0; i < m; i++){
        cin >> items[i];
    }
    sort(items.rbegin(), items.rend());

    vector<llg> prefix(n + 1, 0);
    for (int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + flowers[i];
    }

    vector<vector<llg>> dp(n + 1, vector<llg>(1 << m, 0));
    for (int i = 0; i < n; i++){
        for (int mask = 0; mask < (1 << m); mask++){
            llg curr = dp[i][mask];
            dp[i + 1][mask] = max(dp[i + 1][mask], curr + flowers[i]);
            
            for (int j = 0; j < m; j++){
                if (mask & (1 << j)) continue;

                int next = mask | (1 << j);
                for (int len = 1; len <= k && i + len <= n; len++){
                    llg sum = prefix[i + len] - prefix[i];
                    dp[i + len][next] = max(dp[i + len][next], curr + sum * items[j]);
                }
            }
        }
    }

    llg res = 0;
    for (int i = 0; i < (1 << m); i++){
        res = max(res, dp[n][i]);
    }
    cout << res;

    return 0;
}