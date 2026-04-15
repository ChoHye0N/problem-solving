#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> pipe(n);
    for (int i = 0; i < n; i++){
        cin >> pipe[i];
    }
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        
        pipe[i] -= tmp;
    }
    
    for (int i = 1; i < n; i++){
        pipe[i] = min(pipe[i], pipe[i - 1]);
    }
    
    int q;
    cin >> q;
    
    vector<int> bird(q);
    for (int i = 0; i < q; i++){
        cin >> bird[i];
    }
    
    for (int i = 0; i < q; i++){
        int ans = 0, start = 0, end = pipe.size() - 1;
        
        while (start <= end){
            int mid = start + (end - start) / 2;
            
            if (bird[i] <= pipe[mid]){
                ans = mid + 1;
                start = mid + 1;
            }
            else if (bird[i] > pipe[mid]){
                end = mid - 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}