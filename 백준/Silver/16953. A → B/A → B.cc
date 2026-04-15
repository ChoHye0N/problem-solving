#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int a, b, count = 1;
    cin >> a >> b;

    while (b > a) {
        if (b % 10 == 1) b /= 10;
        else if (b % 2 == 0) b /= 2;
        else break;
        count++;
    }

    cout << (b == a ? count : -1);
    
    return 0;
}