#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> apts(n);
    for (int i = 0; i < n; i++) {
        cin >> apts[i];
    }
    
    int maxVisibleCount = 0;
    
    for (int i = 0; i < n; i++) {
        int visibleCount = 0;
        
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            bool isVisible = true;
            int higherApt = i < j ? i : j;
            int lowerApt = i < j ? j : i;
            double slope = (double)(apts[lowerApt] - apts[higherApt]) / (lowerApt - higherApt);
            
            for (int k = higherApt + 1; k < lowerApt; k++) {
                if (apts[k] >= apts[higherApt] + slope * (k - higherApt)) {
                    isVisible = false;
                    break;
                }
            }
            if (isVisible) visibleCount++;
        }
        maxVisibleCount = max(maxVisibleCount, visibleCount);
    }
    cout << maxVisibleCount << '\n';
    
    return 0;
}