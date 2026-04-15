#include <bits/stdc++.h>
using namespace std;
using llg = long long;

llg f(llg k){
    return 3 * k * (k - 1) + 1;
}

int b_s(vector<int> &arr, int k){
    int start = 0, end = arr.size() - 1, ans = 0;
    
    while (start <= end){
        int mid = start + (end - start) / 2;
        
        if (arr[mid] <= k){
            start = mid + 1;
            ans = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n), brr(m);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++){
        cin >> brr[i];
    }
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < m; i++){
        int cnt = b_s(arr, brr[i]);
        
        if (cnt == 0) {
            cout << 0 << ' ';
            continue;
        }
        
        int start = 1, end = 300000, ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (f(mid) <= cnt) {
                start = mid + 1;
                ans = mid;
            }
            else {
                end = mid - 1;
            }
        }
        cout << ans << ' ';
    }
    
    return 0;
}