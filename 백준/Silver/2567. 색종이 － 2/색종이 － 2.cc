#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    vector<vector<bool>> box(102, vector<bool>(102, false));
    
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        
        for (int r = x; r < x + 10; r++){
            for (int c = y; c < y + 10; c++){
                box[r][c] = true;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= 100; i++){
        for (int j = 0; j <= 100; j++){
            if (box[i][j] != box[i][j + 1]) ans++;
            if (box[i][j] != box[i + 1][j]) ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}