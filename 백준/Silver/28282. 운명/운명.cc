#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    llg n, k;
    cin >> n >> k;
    
    unordered_map<int, llg> umapL, umapR;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        umapL[x]++;
    }
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        umapR[x]++;
    }
    
    llg ans = 0;
    for (int i = 1; i <= k; i++){
        ans += umapL[i] * umapR[i];
    }
    
    cout << n * n - ans;
    
    return 0;
}