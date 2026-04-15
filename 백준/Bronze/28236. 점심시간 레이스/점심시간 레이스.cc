#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> arr(k);
    for (int i = 0; i < k; i++){
        int f, d;
        cin >> f >> d;
        
        arr[i] = f + m - d;
    }
    
    cout << min_element(arr.begin(), arr.end()) - arr.begin() + 1;
    
    return 0;
}