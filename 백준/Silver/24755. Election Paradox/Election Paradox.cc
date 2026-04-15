#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (i < n / 2){
            ans += arr[i];
        }
        else{
            ans += arr[i] / 2;
        }
    }
    
    cout << ans;
    
    return 0;
}