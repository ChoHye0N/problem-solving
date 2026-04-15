#include <bits/stdc++.h>
using namespace std;

int f(int n){
    return n == 0 ? 1 : f(n - 1) * n;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        map<string, int> dict;
        for (int i = 0; i < n; i++){
            string s1, s2;
            cin >> s1 >> s2;
            dict[s2]++;
        }
        
        int ans = 1;
        for (auto &p : dict){
            ans *= (p.second + 1);
        }
        
        cout << --ans << '\n';
    }
    
    return 0;
}