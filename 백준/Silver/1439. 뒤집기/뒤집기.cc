#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string s;
    cin >> s;
    
    vector<int> ans(2, 0);
    for (int i = 0; i < s.size(); i++){
        if (s[i] != s[i + 1]){
            ans[s[i] - '0']++;
        }
    }
    
    cout << min(ans[0], ans[1]);
    
    return 0;
}