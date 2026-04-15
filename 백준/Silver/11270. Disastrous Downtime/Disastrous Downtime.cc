#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(100001, 0);
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }
    
    int curr = 0, ans = 0;
    for (int i = 0; i < 100001; i++){
        curr += arr[i];
        if (i >= 1000) curr -= arr[i - 1000];
        ans = max(ans, curr);
    }
    
    cout << (ans + k - 1) / k;
    
    return 0;
}