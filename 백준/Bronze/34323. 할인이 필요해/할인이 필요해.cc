#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() 
{
    llg n, m, s;
    cin >> n >> m >> s;
    
    llg m1 = m * s, m2 = (m + 1) * (100 - n) * s / 100;
    
    cout << min(m1, m2);
    
    return 0;
}