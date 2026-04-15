#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    long long ans = 0;
    int prev = 0;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        
        ans += temp * 4 + 2;
        
        if (i > 0) ans -= min(prev, temp) * 2;
        
        prev = temp;
    }
    
    cout << ans;
    
    return 0;
}