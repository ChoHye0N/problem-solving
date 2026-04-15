#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_map<int, int> xM, yM;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xM[x]++;
        yM[y]++;
    }
    
    int lines = 0;
    for (auto &p : xM) {
        if (p.second > 1) lines++;
    }
    for (auto &p : yM) {
        if (p.second > 1) lines++;
    }
    
    cout << lines;
    
    return 0;
}