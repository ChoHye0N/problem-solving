#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string n;
    cin >> n;
    
    sort(n.rbegin(), n.rend());
    
    long long rem = 0;
    for (int i = 0; i < n.size(); i++){
        rem = (rem * 10 + (long long)n[i] - '0') % 30;
    }

    rem == 0 ? cout << n : cout << -1;
    
    return 0;
}