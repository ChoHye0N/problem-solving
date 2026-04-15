#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    
    int ans = 0;
    for (int i = 0; i < n && i < m; i++){
        if (arr[i] < 0) break;
        else{
            ans += arr[i];
            n--;
        }
    }
    
    cout << ans;
    
    return 0;
}