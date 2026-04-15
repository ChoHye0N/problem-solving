#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        umap[arr[i]] = i;
    }
    
    vector<int> ans(n);
    
    for (int i = 0; i < n; i++) {
        int minIdx = umap[i + 1];
        
        swap(arr[i], arr[minIdx]);
        umap[arr[minIdx]] = minIdx;
        umap[arr[i]] = i;
        
        ans[arr[i] - 1] += (minIdx - i);
        ans[arr[minIdx] - 1] += (minIdx - i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    
    return 0;
}