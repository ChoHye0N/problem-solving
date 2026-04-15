#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;
    
    int ans = 0;
    for (int i = 0; i < p; i++){
        int x1, y1;
        cin >> x1 >> y1;
        
        if (x1 < x){
            if (pow(x - x1, 2) + pow(y + h / 2 - y1, 2) <= h * h / 4) ans++;
        }
        else if (x1 > x + w){
            if (pow(x + w - x1, 2) + pow(y + h / 2 - y1, 2) <= h * h / 4) ans++;
        }
        else if (x1 >= x && x1 <= x + w && y1 >= y && y1 <= y + h) ans++;
    }
    
    cout << ans;
    
    return 0;
}