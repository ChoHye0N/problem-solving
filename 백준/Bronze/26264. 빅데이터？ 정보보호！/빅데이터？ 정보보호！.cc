#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    string str;
    cin >> n >> str;
    
    int s = 0, b = 0;
    for (char c : str){
        if (c == 's') s++;
        else if (c == 'b') b++;
    }
    
    if (s > b) cout << "security!";
    else if (s < b) cout << "bigdata?";
    else cout << "bigdata? security!";
    
    return 0;
}