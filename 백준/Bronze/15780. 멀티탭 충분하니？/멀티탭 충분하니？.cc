#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    
    int total = 0;
    for (int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        
        if (temp % 2 == 0) total += temp / 2;
        else total += temp / 2 + 1;
    }
    
    cout << (total >= n ? "YES" : "NO");
    
    return 0;
}