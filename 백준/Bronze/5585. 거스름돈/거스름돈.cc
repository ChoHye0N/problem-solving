#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    n = 1000 - n;
    int count = 0;

    for (int i : {500, 100, 50, 10, 5, 1}) {
        count += n / i;
        n %= i;
    }

    cout << count;

    return 0;
}
