#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int d, k;
    cin >> d >> k;
    
    vector<int> dp(d + 1);
    dp[1] = 1;
    dp[2] = 1;
    
    for (int i = 3; i <= d; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    int a = 1, b = 1;
    while (true) {
        if ((k - dp[d - 2] * a) % dp[d - 1] == 0) {
            b = (k - dp[d - 2] * a) / dp[d - 1];
            
            if (a <= b) {
                cout << a << "\n" << b;
                break;
            }
        }
        a++;
    }
    
    return 0;
}