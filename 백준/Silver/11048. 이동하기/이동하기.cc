#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    dp[0][0] = maze[0][0];

    for (int i = 1; i < n; i++)
        dp[i][0] = dp[i - 1][0] + maze[i][0];
    
    for (int j = 1; j < m; j++)
        dp[0][j] = dp[0][j - 1] + maze[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + maze[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << '\n';

    return 0;
}