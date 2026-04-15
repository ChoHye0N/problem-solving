#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    long long ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            ans += temp;
        }
    }
    
    cout << ans;
    
    return 0;
}