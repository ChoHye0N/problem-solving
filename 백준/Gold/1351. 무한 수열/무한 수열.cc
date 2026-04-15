#include <bits/stdc++.h>

using namespace std;
using llg = long long;

unordered_map<llg, llg> arr;

llg dp(llg i, llg p, llg q) {
    if (i == 0) return 1;
    if (arr.find(i) != arr.end()) return arr[i];

    return arr[i] = dp(i / p, p, q) + dp(i / q, p, q);
}

int main() 
{
    llg n, p, q;
    cin >> n >> p >> q;
    
    cout << dp(n, p, q);
    
    return 0;
}