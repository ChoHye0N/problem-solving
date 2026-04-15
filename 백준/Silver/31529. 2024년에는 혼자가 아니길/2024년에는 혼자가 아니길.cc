#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long x, y, ans;
    cin >> x >> y;
    
    if (y < x || y > 2 * x) {
        cout << -1;
    }
    else{
        cout << 506 * (2 * x - y);
    }
    
    return 0;
}