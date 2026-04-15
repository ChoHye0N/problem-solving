#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string a, b;
    cin >> a >> b;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    cout << (stoi(a) > stoi(b) ? stoi(a) : stoi(b));
    
    return 0;
}