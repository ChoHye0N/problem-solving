#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<llg, double>> target(n);
    
    for (int i = 0; i < n; i++){
        target[i].first = i + 1;
        
        llg x, y, v;
        cin >> x >> y >> v;
        
        target[i].second = sqrt(x * x + y * y) / v;
    }
    
    sort(target.begin(), target.end(), [](pair<llg, double>& a, pair<llg, double>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    for (int i = 0; i < n; i++){
        cout << target[i].first << '\n';
    }
    
    return 0;
}