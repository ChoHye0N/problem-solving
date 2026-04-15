#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int sum = 0;
    string ans;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        sum += temp;
    }
    
    sum % 3 == 0 ? ans = "yes" : ans = "no";
    cout << ans << '\n';

    return 0;
}