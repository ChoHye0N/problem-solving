#include <bits/stdc++.h>

using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<llg> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    llg total = accumulate(arr.begin(), arr.end(), 0), ans = 0, sq = 0, sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sq += arr[i] * arr[i];
        sum += arr[i];
        ans = max(ans, sq * (total - sum));
    }
    
    cout << ans;
    
    return 0;
}
