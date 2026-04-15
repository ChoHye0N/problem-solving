#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    map<string, int, greater<string>> worker;
    for (int i = 0; i < n; i++){
        string name, op;
        cin >> name >> op;
        
        if (op == "enter"){
            worker[name] = 1;
        }
        
        else if (op == "leave"){
            worker[name] = 0;
        }
    }
    
    for (auto& m : worker){
        if (m.second){
            cout << m.first << '\n';
        }
    }
    
    return 0;
}