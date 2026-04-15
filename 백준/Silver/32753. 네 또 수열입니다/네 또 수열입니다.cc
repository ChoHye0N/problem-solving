#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    if(n == 1) {
        for (int i = 0; i < k; i++){
            cout << "1" << (i + 1 == k ? "" : " ");
        }
    }
    else if(n == 2 && k == 1) {
        cout << "1 2";
    }
    else {
        cout << "-1";
    }
    
    return 0;
}