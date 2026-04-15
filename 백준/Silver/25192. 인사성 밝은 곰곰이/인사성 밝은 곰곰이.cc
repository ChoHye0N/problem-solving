#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    map<string, int> umap;
    int ans = 0;
    while (t--){
        string msg;
        cin >> msg;
        
        if (msg == "ENTER"){
            umap.clear();
            continue;
        }
        
        umap[msg]++;
        
        if (umap[msg] <= 1) ans++;
    }
    
    cout << ans;
    
    return 0;
}