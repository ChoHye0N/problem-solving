#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<llg>> pf(n + 1, vector<llg>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int tmp;
            cin >> tmp;
            
            pf[i][j] = pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1] + tmp;
        }
    }
    
    int k;
    cin >> k;
    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << pf[x2][y2] - pf[x1 - 1][y2] - pf[x2][y1 - 1] + pf[x1 - 1][y1 - 1] << '\n';
    }
    
    return 0;
}