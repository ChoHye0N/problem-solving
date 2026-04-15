#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, ans;
    cin >> n;
    
    if (n <= 2) ans = 4;
    else {
        int root = (int)(sqrt(n) + 0.5);
        
        if (root * root >= n) ans = (root - 1) * 4;
        else ans = ((root - 1) * 2) + (root * 2);
    }

    cout << ans;
    
    return 0;
}