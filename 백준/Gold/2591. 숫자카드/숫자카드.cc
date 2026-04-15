#include <bits/stdc++.h>
using namespace std;

const int MAX = 34;

int main() {
    string str;
    cin >> str;
    
    int nLen = str.size();

    vector<int> dp(nLen + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= nLen; i++) {
        int d1 = stoi(str.substr(i - 1, 1));

        if (1 <= d1 && d1 <= 9) dp[i] += dp[i - 1];
        if (i > 1) {
            int d2 = stoi(str.substr(i - 2, 2));
            
            if (10 <= d2 && d2 <= 34) dp[i] += dp[i - 2];
        }
    }

    cout << dp[nLen];

    return 0;
}