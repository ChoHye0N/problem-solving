#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str;
    int k;
    
    cin >> str >> k;
    
    map<char, bool> arr;
    for (int i = 0; i < str.size();) {
        char c = tolower(str[i]);
        int cnt = 0;
        
        if (arr[c]) {
            while (i < str.size() && tolower(str[i]) == c) i++;
            continue;
        }
    
        while (i < str.size() && tolower(str[i]) == c) {
            cnt++;
            i++;
        }
        
        arr[c] = true;
        
        if (cnt >= k) cout << 1;
        else cout << 0;
    }
    
    return 0;
}