#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    map<int, float> marr;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int p;
            float r;
            cin >> p >> r;
            
            if (i > 0){
                marr[p] = max(marr[p], r);
            }
            else{
                marr[p] = r;
            }
        }
    }
    
    vector<pair<int, float>> arr(marr.begin(), marr.end());
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });
    
    int idx = 0;
    float ans = 0.;
    for (auto &tmp : arr){
        if (idx >= k) break;
        
        ans += tmp.second;
        idx++;
    }
    
    printf("%.1f", ans);
    
    return 0;
}