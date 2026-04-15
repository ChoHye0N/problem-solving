#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());

    int ans = 5;
    for (int i = 0; i < n; i++) {
        int count = 0;
        
        for (int j = i; j < n && arr[j] <= arr[i] + 4; j++) {
            count++;
        }

        ans = min(ans, 5 - count);
    }

    cout << ans;
    
    return 0;
}