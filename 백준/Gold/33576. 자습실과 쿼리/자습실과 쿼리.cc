#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> arr(n, 0);
    for (int i = 0; i < m; i++){
        int w, d;
        cin >> w >> d;
        
        arr[w - 1] = d;
    }
    
    vector<int> brr(q);
    for (int i = 0; i < q; i++){
        cin >> brr[i];
        
        brr[i]--;
    }
    
    vector<llg> pf(n + 1, 0);
    for (int i = 0; i < n; i++){
        pf[i + 1] = pf[i] + arr[i];
    }
    
    int l = 0, r = n - 1;
    
    for (int i = 0; i < q; i++){
        int mid = brr[i];
        
        if (mid < l || mid > r){
            cout << "0\n";
            continue;
        }
        
        llg lw = pf[mid] - pf[l], rw = pf[r + 1] - pf[mid + 1], ans = 0;
        
        if (lw > rw){
            r = mid;
            ans = rw;
        } 
        else if (rw > lw){
            l = mid;
            ans = lw;
        } 
        else{
            if (mid <= n / 2){
                l = mid;
                ans = lw;
            } 
            else{
                r = mid;
                ans = rw;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}