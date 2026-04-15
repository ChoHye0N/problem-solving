#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int x, y;
    cin >> x >> y;
    
    cout << stoi(string(x, '1')) + stoi(string(y, '1'));
    
    return 0;
}