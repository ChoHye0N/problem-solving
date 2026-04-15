#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k, l;
    cin >> k >> l;
    
    list<string> lst;
    unordered_map<string, list<string>::iterator> pt;
    
    for (int i = 0; i < l; i++) {
        string stud;
        cin >> stud;
        
        if (pt.count(stud)) {
            lst.erase(pt[stud]);
            pt.erase(stud);
        }
        
        lst.push_back(stud);
        pt[stud] = prev(lst.end());
    }
    
    int cnt = 0;
    for (auto it = lst.begin(); it != lst.end() && cnt < k; it++) {
        cout << *it << '\n';
        cnt++;
    }
    
    return 0;
}