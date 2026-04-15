#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int t = 0; t < n; t++) {
        int s, ans = 0;
        cin >> s;
        
        vector<int> red, blue;
        for (int i = 0; i < s; i++) {
            string temp;
            cin >> temp;
            
            int num = stoi(temp.substr(0, temp.size() - 1));
            
            if (temp[temp.size() - 1] == 'R') red.push_back(num);
            else blue.push_back(num);
        }
        
        if (red.size() == 0 || blue.size() == 0) {
            ans = 0;
        }
        else{
            sort(red.rbegin(), red.rend());
            sort(blue.rbegin(), blue.rend());
            
            int use = min(red.size(), blue.size());
            
            for (int i = 0; i < use; i++) {
                ans += red[i] + blue[i];
            }
            
            ans -= 2 * use;
        }
        
        printf("Case #%d: %d\n", t + 1, ans);
    }
    
    return 0;
}