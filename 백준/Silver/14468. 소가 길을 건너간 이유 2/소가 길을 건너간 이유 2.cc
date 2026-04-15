#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str;
    cin >> str;
    
    int ans = 0;
    
    for (int i = 'A'; i <= 'Z'; i++){
        for (int j = i + 1; j <= 'Z'; j++){
            int a1 = str.find(i), a2 = str.rfind(i), 
                b1 = str.find(j), b2 = str.rfind(j);
            
            if ((a1 < b1 && b1 < a2 && a2 < b2) || 
                (b1 < a1 && a1 < b2 && b2 < a2))
                ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}