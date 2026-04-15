#include <bits/stdc++.h>

using namespace std;

string to_sb(int n) {
    string ans = "";
    
    for (int i = 3; i >= 0; i--) {
        if ((n >> i) & 1) ans += "딸기";
        else ans += "V";
    }
    
    return ans;
}

int get_th_n(int n) {
    int cycle = (n - 1) % 28;
    
    if (cycle < 15) return cycle + 1;
    return 29 - cycle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << to_sb(get_th_n(n)) << '\n';
    }
    
    return 0;
}