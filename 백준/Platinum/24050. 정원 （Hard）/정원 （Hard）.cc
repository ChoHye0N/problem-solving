#include <bits/stdc++.h>

using namespace std;

bool is_odd_comb(int n, int k) {
    return (k & ~n) == 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> col(n), row(m);
    for (int i = 0; i < n; i++){
        cin >> col[i];
    }
    
    for (int j = 0; j < m; j++){
        cin >> row[j];
    }
    
    int ans = 0, total = n + m - 2;
    for (int i = 0; i < n; i++) {
        if (is_odd_comb(total - i, m - 1)) ans ^= col[i];
    }
    for (int j = 0; j < m; j++) {
        if (is_odd_comb(total - j, n - 1)) ans ^= row[j];
    }
    
    cout << ans;
    
    return 0;
}