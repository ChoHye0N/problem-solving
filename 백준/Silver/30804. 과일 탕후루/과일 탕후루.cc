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
    
    map<int, int> freq;
    int l = 0, ans = 0;
    
    for (int r = 0; r < n; r++){
        freq[arr[r]]++;
        
        while (freq.size() > 2){
            freq[arr[l]]--;
            
            if (freq[arr[l]] == 0){
                freq.erase(arr[l]);
            }
            l++;
        }
        
        ans = max(ans, r - l + 1);
    }
    
    cout << ans;
    
    return 0;
}