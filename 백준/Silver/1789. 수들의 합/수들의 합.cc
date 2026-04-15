#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    llg s;
    cin >> s;
    
    cout << (llg)(sqrt(8 * s + 1) - 1) / 2;
    
    return 0;
}