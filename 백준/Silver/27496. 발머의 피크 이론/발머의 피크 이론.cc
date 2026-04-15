#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, l;
    cin >> n >> l;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = 0, total = 0;
    for (int i = 0; i < n; i++) {
        if (i < l)
            total += arr[i];
        else
            total += arr[i] - arr[i - l];
        
        if (total >= 129 && total <= 138) ans++;
    }
    
    cout << ans;
    
    return 0;
}