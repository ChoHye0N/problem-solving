#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;

int main() {
    string str;
    cin >> str;

    if (str.size() == 0 || str[0] == '0') {
        cout << 0;
        return 0;
    }

    vector<int> dp(str.size() + 1, 0);
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= str.size(); i++) {
        int curr = i - 1;

        if (str[curr] != '0') {
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        }

        int chk = (str[curr - 1] - '0') * 10 + str[curr] - '0';
        if (chk >= 10 && chk <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }

        if (dp[i] == 0) {
            cout << 0;
            return 0;
        }
    }

    cout << dp[str.size()];

    return 0;
}