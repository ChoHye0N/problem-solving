#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    int n;
    cin >> n;
    
    vector<llg> hp;
    for (int i = 0; i < n; i++){
        llg p, total = 0;
        cin >> p;
        
        for (int j = 0; j < p; j++){
            int temp;
            cin >> temp;
            total += temp;
        }
        hp.push_back(total);
    }
    
    sort(hp.begin(), hp.end());
    
    llg ans = hp[0];
    for (int i = 1; i < hp.size(); i++){
        hp[i] += hp[i - 1];
        ans += hp[i];
    }
    
    cout << ans;
    
    return 0;
}