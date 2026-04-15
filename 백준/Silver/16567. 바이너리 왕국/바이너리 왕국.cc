#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    set<int> arrS;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        if (temp == 1) arrS.insert(i);
    }
    
    int count = 0;
    for (auto it = arrS.begin(); it != arrS.end(); it++){
        if (it == arrS.begin() || *prev(it) + 1 != *it)
            count++;
    }
    
    for (int i = 0; i < m; i++){
        int op, x;
        cin >> op;
        
        if (op == 0){
            cout << count << '\n';
        }
        else if (op == 1){
            cin >> x;
            if (arrS.count(--x)) continue;
            
            bool left = arrS.count(x - 1), right = arrS.count(x + 1);
            
            if (left && right) count--;
            else if (!left && !right) count++;
            
            arrS.insert(x);
        }
    }
    
    return 0;
}