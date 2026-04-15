#include <bits/stdc++.h>
using namespace std;
using llg = long long;

const int MOD = 1000000007;

llg pow_f(llg n, llg k){
    llg res = 1;
    
    while (k > 0){
        if (k % 2 == 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        k /= 2;
    }
    return res;
}

int main() 
{
    llg n, m;
    cin >> n >> m;
    
    cout << (pow_f(m, n) - pow_f(m - 1, n) + MOD) % MOD;
    
    return 0;
}