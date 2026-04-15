#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int idx = 0;
    while (true){
        int l, p, v;
        cin >> l >> p >> v;
        
        if (l == 0 && p == 0 && v == 0) break;
        
        int ans = v / p * l;
        if (l > v % p) ans += v % p;
        else ans += l;
        
        printf("Case %d: %d\n", ++idx, ans);
    }
    
    return 0;
}