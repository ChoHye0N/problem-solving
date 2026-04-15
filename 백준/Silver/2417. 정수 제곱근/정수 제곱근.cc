#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    llg n;
    cin >> n;
    
    if (n == 0){
        cout << 0;
        return 0;
    }
    
    llg start = 1, end = n, ans = end;
    
    while (start <= end){
        llg mid = start + (end - start) / 2;
        
        if (mid > n / mid){
            ans = mid;
            end = mid - 1;
        }
        else if (mid < n / mid){
            start = mid + 1;
        }
        else {
            mid * mid == n ? ans = mid : ans = mid + 1;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}