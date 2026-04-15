#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        ans += temp;
    }
    
    cout << (ans % x == 0 ? 1 : 0);
    
    return 0;
}