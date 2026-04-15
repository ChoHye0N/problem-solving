#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    map<int, int> marr;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        
        marr[tmp]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= 50; i++){
        int multi = 1;
        
        for (int j = 1; j <= i; j++){
            multi *= marr[j];
        }
        ans += multi;
    }
    
    cout << ans;
    
    return 0;
}