#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    
    string checkS = "32123333113133122212112221";
    vector<int> v;
    
    for (char c : str) 
        v.push_back(checkS[c - 'A'] - '0');
    
    while (v.size() > 1) {
        vector<int> next;
        
        for (int i = 0; i < v.size(); i += 2) {
            if (i + 1 < v.size()){
                next.push_back((v[i] + v[i + 1]) % 10);
            }
            else{
                next.push_back(v[i]);
            } 
        }
        v = next;
    }
    
    cout << (v[0] % 2 ? "I'm a winner!" : "You're the winner?");
    
    return 0;
}