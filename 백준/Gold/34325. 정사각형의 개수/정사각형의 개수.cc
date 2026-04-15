#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int MOD = 1000000007;

llg pow_f(llg n, llg k){
    llg res = 1;
    
    while (k > 0){
        if (k % 2 == 1){
            res = res * n % MOD;
        }
        
        n = n * n % MOD;
        k = k / 2;
    }
    
    return res;
}

int main() 
{
    int n, k;
    cin >> n >> k;
    
    llg ans = 0;
    
    for (int i = 1; i <= n; i++){
        llg a, blck = n - i + 1;
        
        a = 2 * blck * (blck - 1) % MOD;
        
        if (blck % 2 == 1) {
            a = a + 1;
        }
        
        ans = (ans + a * pow_f(k, i)) % MOD;
    }
    
    cout << ans;
    
    return 0;
}