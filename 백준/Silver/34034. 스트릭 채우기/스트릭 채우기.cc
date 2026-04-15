#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    
    int need = k - m;
    if (need <= 0){
        for (int i = 0; i < k; i++) cout << 0 << ' ';
        return 0;
    }
    if (need > n){
        cout << -1;
        return 0;
    }
    sort(arr.begin(), arr.end());
    
    llg sum = 0;
    for (int i = 0; i < need; i++){
        sum += arr[i].first;
    }
    if (sum > k){
        cout << -1;
        return 0;
    }
    
    vector<int> ans(k, 0);
    llg day = 0;
    for (int i = 0; i < need; i++){
        day += arr[i].first;
        ans[day - 1] = arr[i].second;
    }
    
    for (int i = 0; i < k; i++){
        cout << ans[i] << ' ';
    }
    
    return 0;
}