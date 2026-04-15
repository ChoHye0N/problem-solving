#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        if (a == 0 && b == 0){
            cout << 0 << '\n';
            continue;
        }
        
        int d = (b + 3) / 4, ans = max(0, d - a) + max(0, 3 * max(a, d) - b);
        
        cout << ans << '\n';
    }
    
    return 0;
}