#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        
        int w = floor(sqrt(n));
        int h = (n + w - 1) / w;
        cout << 2 * (w + h) << '\n';
    }
    
    return 0;
}