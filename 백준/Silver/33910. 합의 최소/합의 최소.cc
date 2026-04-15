#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    llg ans = 0;
    int m = 1e9;
    for (int i = n - 1; i >= 0; i--){
        m = min(m, arr[i]);
        ans += m;
    }
    
    cout << ans;
    
    return 0;
}