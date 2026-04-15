#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str;
    cin >> str;
    
    for (int len = 1; len <= str.size() / 2; len++){
        int prev = stoi(str.substr(0, len));
        int curr = prev, pos = len;
        
        while (true){
            string next = to_string(curr + 1);
            int l = next.size();
            
            if (pos + l > str.size() || str.substr(pos, l) != next) break;
            
            curr++;
            pos += l;
        }
        
        if (pos == str.size()){
            cout << prev << ' ' << curr;
            return 0;
        }
    }
    
    cout << stoi(str) << ' ' << stoi(str);
    
    return 0;
}