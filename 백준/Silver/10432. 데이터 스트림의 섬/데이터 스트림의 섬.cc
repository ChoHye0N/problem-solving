#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int p;
    cin >> p;
    
    for (int t = 0; t < p; t++) {
        int tc, arr[12];
        cin >> tc;
        
        for (int i = 0; i < 12; i++) {
            cin >> arr[i];
        }
        
        int cnt = 0;
        for (int i = 1; i < 11; i++) {
            for (int j = i; j < 11; j++) {
                bool isLand = true;
                
                for (int k = i; k <= j; k++) {
                    if (arr[k] <= arr[i - 1] || arr[k] <= arr[j + 1]) {
                        isLand = false;
                        break;
                    }
                }
                
                if (isLand) cnt++;
            }
        }
        
        cout << tc << ' ' << cnt << '\n';
    }
    
    return 0;
}