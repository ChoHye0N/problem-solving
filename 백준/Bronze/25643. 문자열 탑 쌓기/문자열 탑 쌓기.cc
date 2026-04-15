#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, m, ans = 1;
    cin >> n >> m;
    
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        bool check = false;
        
        for (int len = 1; len <= m; len++) {
            bool match1 = true, match2 = true;
            
            for (int j = 0; j < len; j++) {
                if (strs[i][m - len + j] != strs[i + 1][j]) {
                    match1 = false;
                    break;
                }
            }
            for (int j = 0; j < len; j++) {
                if (strs[i + 1][m - len + j] != strs[i][j]) {
                    match2 = false;
                    break;
                }
            }
            
            if (match1 || match2) {
                check = true;
                break;
            }
        }
        
        if (!check) {
            ans = 0;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}