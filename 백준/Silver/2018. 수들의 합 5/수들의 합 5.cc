#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int ptr1 = 1, ptr2 = 1, count = 0;
    
    // O(n)
    while (ptr1 <= n){
        int ans = (ptr2 - ptr1 + 1) * (ptr1 + ptr2) / 2;
        
        if (ans == n){
            count++;
            ptr2++;
        }
        else if (ans > n) ptr1++;
        else ptr2++;
    }
    
    cout << count;
    
    return 0;
}