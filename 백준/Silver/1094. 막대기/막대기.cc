#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int x, count = 0;
    cin >> x;
    
    while (x > 0){
        count += x % 2;
        x /= 2;
    }
    
    cout << count;
    
    return 0;
}