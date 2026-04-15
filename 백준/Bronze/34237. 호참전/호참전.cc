#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        
        arr[i].first = a, arr[i].second = b;
    }
    
    for (int i = 0; i < m; i++){
        int t, x, y;
        cin >> t >> x >> y;
        
        int ans = 0;
        for (int j = 0; j < arr.size(); j++){
            if (arr[j].first >= x && arr[j].second >= y 
                && (t >= arr[j].first + arr[j].second)) ans++;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}