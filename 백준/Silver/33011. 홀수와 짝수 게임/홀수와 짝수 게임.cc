#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        
        vector<int> even, odd;
        for (int idx = 0; idx < n; idx++){
            int temp;
            cin >> temp;
            
            if (temp % 2 == 0) even.push_back(temp);
            else odd.push_back(temp);
        }
        
        if (even.size() == odd.size() || max(even.size(), odd.size()) % 2 == 0){
            cout << "heeda0528\n";
        }
        else cout << "amsminn\n";
    }
    
    return 0;
}