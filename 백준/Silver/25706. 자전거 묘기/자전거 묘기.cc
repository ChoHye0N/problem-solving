#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> road(n), dp(n);
    for (int i = 0; i < n; i++) {
        cin >> road[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) dp[i] = 1;
        else {
            int next = i + road[i] + 1;
            
            if (next >= n) {
                dp[i] = 1;
            }
            else {
                dp[i] = dp[next] + 1;
            }
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        cout << dp[i] << ' ';
    }
    cout << dp[n - 1];
    
    return 0;
}