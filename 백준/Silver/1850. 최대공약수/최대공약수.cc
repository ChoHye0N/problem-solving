#include <bits/stdc++.h>

using namespace std;
using llg = long long;

llg gcd(llg a, llg b){
    return b ? gcd(b, a % b) : a;
}

int main() 
{
    llg a, b;
    cin >> a >> b;
    
    int size = gcd(a, b);
    string ans = "";
    for (int i = 0; i < size; i++){
        ans += '1';
    }
    
    cout << ans;
    
    return 0;
}