#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    map<int, string> mapArr;
    vector<string> ans;
    for (int i = 0; i < n; i++){
        string name, state, icpc;
        int shake, apc;
        cin >> name >> state >> icpc >> shake >> apc;
        
        if (state == "jaehak" && icpc == "notyet" && (shake > 3 || shake == -1)){
            mapArr[apc] = name;
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (ans.size() >= 10) break;
        if (mapArr.find(i) != mapArr.end()) ans.push_back(mapArr[i]);
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (string str : ans){
        cout << str << '\n';
    }
    
    return 0;
}