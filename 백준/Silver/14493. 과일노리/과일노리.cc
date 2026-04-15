#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int t = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        if (t % (a + b) < b) {
            t += b - (t % (a + b));
        }
        
        t++;
    }
    
    cout << t;
    
    return 0;
}