#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            freq[temp]++;
        }
    }
    
    int oddCount = 0;
    for (auto& p : freq) {
        if (p.second % 2 == 1) {
            oddCount++;
        }
    }
    
    bool flag = m % 2 == 0 ? oddCount == 0 : oddCount <= n;
    
    cout << (flag ? "YES" : "NO");
    
    return 0;
}