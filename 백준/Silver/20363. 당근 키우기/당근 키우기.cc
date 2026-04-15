#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    llg x, y;
    cin >> x >> y;
    
    cout << x + y + min(x / 10, y / 10);
    
    return 0;
}