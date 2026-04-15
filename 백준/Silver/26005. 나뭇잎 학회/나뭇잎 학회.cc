#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, ans;
    cin >> n;
    
    cout << (n == 1 ? 0 : (n * n + 1) / 2);
    
    return 0;
}