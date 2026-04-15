#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_map<string, double> umapN, umapP;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        
        umapN[str]++;
        umapP[str] += i + 1;
    }
    
    vector<pair<string, double>> ans(umapP.begin(), umapP.end());
    for (auto &p : ans){
        p.second /= umapN[p.first];
    }
    
    sort(ans.begin(), ans.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });
    
    for (auto &p : ans){
        cout << p.first << '\n';
    }
    
    return 0;
}