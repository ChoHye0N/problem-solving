#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_map<string, bool> umap;
    int ans = 0;
    while (n--){
        string s1, s2;
        cin >> s1 >> s2;
        
        if (umap[s1] || umap[s2]){
            umap[s1] = true, umap[s2] = true;
            
        }
        else if(s1 == "ChongChong" || s2 == "ChongChong"){
            umap[s1] = true, umap[s2] = true;
        }
    }
    
    for (auto &p : umap){
        if (p.second){
            ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}