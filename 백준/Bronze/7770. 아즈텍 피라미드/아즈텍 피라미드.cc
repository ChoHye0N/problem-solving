#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    llg n;
    cin >> n;
    
    llg h = 0, used = 0;
    for (llg i = 1; ; i++){
        llg block = 2 * (i * i - i) + 1;
        if (used + block > n) break;
        used += block;
        h++;
    }
    
    cout << h;
    
    return 0;
}