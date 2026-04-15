#include <bits/stdc++.h>

using namespace std;
using llg = long long;

double damage_until(llg t, llg r, llg a, llg d) {
    if (t <= 0) return 0;
    
    llg rem = t % (r + a);
    double res = (double)(t / (r + a)) * d;
    
    if (rem > r) {
        llg active = rem - r;
        
        if (active > a) active = a;
        res += (double)active * d / a;
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, s, e;
    cin >> n >> s >> e;
    
    double total = 0;
    for (int i = 0; i < n; i++) {
        llg r, a, d;
        cin >> r >> a >> d;
        
        total += damage_until(e, r, a, d) - damage_until(s, r, a, d);
    }
    
    cout << fixed << setprecision(10) << total / (e - s);
    
    return 0;
}