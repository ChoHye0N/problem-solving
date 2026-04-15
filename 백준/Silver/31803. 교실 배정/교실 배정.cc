#include <bits/stdc++.h>
using namespace std;
using llg = long long;

llg p_f(llg n){
    return n == 2 ? 1 : (n - 1) * p_f(n - 2);
}

int main() 
{
    int n;
    cin >> n;
    
    cout << (n % 2 == 0 ? p_f(n) : n * p_f(n - 1));
    
    return 0;
}