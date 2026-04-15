#include <bits/stdc++.h>

using namespace std;
using ullg  = unsigned long long;

string ten2two(ullg n){
    string str = "";
    
    for (int i = 0; i < 8; i++){
        str.push_back((n % 2) + '0');
        n /= 2;
    }
    reverse(str.begin(), str.end());
    
    return str;
}

ullg to_one(string n){
    string temp = "";
    ullg ans = 0;
    
    for (int i = 0; i <= n.size(); i++) {
        if (i == n.size() || n[i] == '.') {
            ans = ans * 256 + atoll(temp.c_str());
            temp.clear();
        }
        else temp.push_back(n[i]);
    }
    
    return ans;
}

string to_two(ullg n){
    string str = "";
    
    for (int i = 0; i < 8; i++){
        str = ten2two(n & 0xFF) + str;
        n >>= 8;
    }

    string ans = "";
    for (int i = 0; i < 8; i++) {
        if (i > 0) ans += '.';
        
        ullg val = 0;
        
        for (int j = 0; j < 8; j++) {
            val = val * 2 + (str[i * 8 + j] - '0');
        }
        ans += to_string(val);
    }
    return ans;
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        int m;
        cin >> m;
        
        if (m == 1) {
            string n;
            cin >> n;
            
            cout << to_one(n) << '\n';
        }
        else if (m == 2){
            ullg n;
            cin >> n;
            
            cout << to_two(n) << '\n';
        }
    }
    
    return 0;
}