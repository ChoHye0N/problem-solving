#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    int n;
    cin >> str >> n;
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        temp = temp + temp.substr(0, str.size() - 1);
        
        for (int j = 0; j < temp.size(); j++){
            if (str == (temp.substr(j, str.size()))){
                ans++;
                break;
            }
        }
        
    }
    
    cout << ans;
    
    return 0;
}