#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str;
    cin >> str;
    
    transform(str.begin(), str.end(), str.begin(), [](char c){
        return islower(c) ? toupper(c) : tolower(c);
    });
    
    cout << str;
    
    return 0;
}