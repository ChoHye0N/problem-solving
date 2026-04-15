#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        llg n, p3 = 1, ans = 0;
        cin >> n;
        
        while (n > 0){
            if (n & 1) {
                ans += p3;
            }
            
            p3 *= 3;
            n >>= 1;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}