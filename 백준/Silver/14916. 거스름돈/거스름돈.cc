#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int coin = 0;
    
    while (n > 0) {
        if (n % 5 == 0) {
            coin += n / 5;
            n = 0;
            break;
        }
        n -= 2;
        coin++;
    }
    
    if (n < 0) {
        cout << -1;
    }
    else {
        cout << coin;
    }
    
    return 0;
}