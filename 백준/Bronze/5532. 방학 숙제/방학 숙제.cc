#include <bits/stdc++.h>

using namespace std;

int main() 
{
    float l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    
    cout << l - max(ceil(a / c), ceil(b / d));
    
    return 0;
}