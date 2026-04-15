#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    int n;
    cin >> n;
    
    vector<llg> dp(35, 0);
    llg total = 1;
    
    for(int i=0; i<n; i++){
      dp[i] = total;
      for(int j=0; j<i; j++){
        total += dp[j]*dp[i-j];
      }
    }
    
    cout << total << '\n';
    
    return 0;
}