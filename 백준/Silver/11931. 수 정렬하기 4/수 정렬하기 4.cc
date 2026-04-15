#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    
    for (int i = 0; i < n - 1; i++){
        cout << arr[i] << '\n';
    }
    cout << arr[n - 1];
    
    return 0;
}