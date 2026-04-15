#include <bits/stdc++.h>
using namespace std;

string add(string a, string b){
    string res = "";
    int carry = 0;
    
    while (!a.empty() || !b.empty() || carry){
        int tmp = 0;
        
        if (!a.empty()){
            tmp += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()){
            tmp += b.back() - '0';
            b.pop_back();
        }
        
        tmp += carry;
        carry = tmp / 10;
        res.push_back(tmp % 10 + '0');
    }
    reverse(res.begin(), res.end());
    
    return res;
}

int main() 
{
    int n;
    cin >> n;
    
    if (n == 0){
        cout << 0;
        return 0;
    }
    
    else if (n == 1 || n == 2){
        cout << 1;
        return 0;
    }
    
    vector<string> dp(n + 1, "0");
    dp[0] = dp[1] = dp[2] = "1";
    
    for (int i = 3; i <= n; i++){
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }
    
    cout << dp[n];
    
    return 0;
}