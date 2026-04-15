#include <bits/stdc++.h>
using namespace std;

int fb(int n){
    if (n == 1 || n == 2) return 1;
    else if (n == 0) return 0;
    return fb(n - 1) + fb(n - 2);
}

int main() 
{
    int n;
    cin >> n;
    
    cout << fb(n);
    
    return 0;
}