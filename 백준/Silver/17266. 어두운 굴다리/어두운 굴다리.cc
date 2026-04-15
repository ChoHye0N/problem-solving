#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(m);
    for (int i = 0; i < m; i++){
        cin >> arr[i];
    }
    
    int ans = max(0, arr[0] - 0);
    ans = max(ans, n - arr[m - 1]);
    
    for (int i = 1; i < m; i++){
        int diff = arr[i] - arr[i - 1];
        ans = max(ans, (diff + 1) / 2);
    }
    
    cout << ans;
    
    return 0;
}