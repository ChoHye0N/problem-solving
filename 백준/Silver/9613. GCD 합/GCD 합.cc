#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--){
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        
        vector<int> ans;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                ans.push_back(gcd(arr[i], arr[j]));
            }
        }
        
        cout << accumulate(ans.begin(), ans.end(), 0LL) << '\n';
    }
    
    return 0;
}