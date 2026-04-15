#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    bool ans = false;
    
    if (n == 1 && m == 1){
        ans = true;
    } 
    else if (n == 1 || m == 1){
        if (x1 == x2 && y1 == y2) ans = true;
    } 
    else{
        if (x1 == x2 && y1 == y2) ans = true;
        else if ((x1 + y1) % 2 == (x2 + y2) % 2) ans = true;
    }
    
    cout << (ans ? "YES" : "NO");
    
    return 0;
}