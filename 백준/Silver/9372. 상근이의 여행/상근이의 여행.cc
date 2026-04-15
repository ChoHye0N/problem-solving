#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    
    for (int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        
        vector<int> plane(n, 0);
        for (int j = 0; j < m; j++){
            int a, b;
            cin >> a >> b;
            
            if (plane[a] && plane[b]) continue;
            if (!plane[a]) plane[a]++;
            if (!plane[b]) plane[b]++;
        }
        cout << accumulate(plane.begin(), plane.end(), 0) << '\n';
    }
    
    return 0;
}