#include <bits/stdc++.h>
using namespace std;

int d;

int recur(string &s, int l, int r){
    d++;
    
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recur(s, l + 1, r - 1);
}

int is_p(string &s){
    return recur(s, 0, s.size() - 1);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--){
        string str;
        cin >> str;
        
        d = 0;
        
        cout << is_p(str) << ' ' << d << '\n';
    }
    
    return 0;
}