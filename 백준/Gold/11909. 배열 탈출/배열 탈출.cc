#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            dp[i][j] = INF;
        }
    }

    dp[1][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;

            if (i > 1) {
                int c = 0;
                
                if (arr[i - 1][j] <= arr[i][j]) {
                    c = arr[i][j] - arr[i - 1][j] + 1;
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + c);
            }
            if (j > 1) {
                int c = 0;
                if (arr[i][j - 1] <= arr[i][j]) {
                    c = arr[i][j] - arr[i][j - 1] + 1;
                }
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + c);
            }
        }
    }

    cout << dp[n][n];

    return 0;
}