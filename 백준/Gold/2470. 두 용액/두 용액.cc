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
    
    sort(arr.begin(), arr.end());
    
    int start = 0, end = n - 1;
    int minDiff = INT_MAX;
    pair<int, int> ans = { 0, 0 };
    
    while (start < end){
        int total = arr[start] + arr[end];
        
        if (abs(total) < minDiff){
            minDiff = abs(total);
            ans = { arr[start], arr[end] };
        }
        
        if (total < 0) start++;
        else end--;
    }
    
    cout << ans.first << ' ' << ans.second;
    
    return 0;
}