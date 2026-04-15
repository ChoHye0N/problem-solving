#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n1;
    string n2;
    cin >> n1 >> n2;
    
    int ans = 0;
    for (int i = 0; i < 3; i++){
        int temp = n1 * (n2[2 - i] - '0') ;
        cout << temp << '\n';
        ans += temp * pow(10, i);
        
    }
    
    cout << ans;
    
    return 0;
}