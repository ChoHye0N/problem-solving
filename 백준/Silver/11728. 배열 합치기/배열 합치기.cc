#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n + m);
    for (int i = 0; i < n + m; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n + m; i++){
        cout << arr[i] << ' ';
    }
    
    return 0;
}