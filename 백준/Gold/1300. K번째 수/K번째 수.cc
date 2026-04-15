#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    llg n, k;
    cin >> n >> k;
    
    llg start = 1, end = n * n, ans = 0;
    while (start <= end){
        llg mid = start + (end - start) / 2, temp = 0;
        
        for (int i = 1; i <= n; i++){
            temp += min(n, mid / i);
        }
        
        if (k <= temp){
            end = mid - 1;
            ans = mid;
        }
        else{
            start = mid + 1;
        }
    }
    
    cout << ans;
    
    return 0;
}