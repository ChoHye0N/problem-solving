#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str;
    cin >> str;
    
    int und = 0, col = 0;
    for (char c : str){
        if (c == ':') col++;
        else if (c == '_') und++;
    }
    
    cout << str.size() + col + und * 5;
    
    return 0;
}