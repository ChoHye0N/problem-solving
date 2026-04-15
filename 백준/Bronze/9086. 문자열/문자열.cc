#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        string str;
        cin >> str;
        
        if (t < i - 1)
            cout << str[0] << str[str.size() - 1];
        else
            cout << str[0] << str[str.size() - 1] << '\n';
    }
    
    return 0;
}