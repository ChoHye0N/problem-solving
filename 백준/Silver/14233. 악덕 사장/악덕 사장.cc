#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<llg> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    llg start = 1, end = arr[n - 1], ans = 0;
    
    while (start <= end){
        llg mid = (start + end) / 2;
        bool flag = true;
        
        for (int i = 0; i < n; i++){
            if ((i + 1) * mid > arr[i]){
                flag = false;
                break;
            }
        }
        
        if (flag) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    cout << ans;
    
    return 0;
}