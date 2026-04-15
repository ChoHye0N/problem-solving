#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> page(n);
    for (int i = 0; i < n; i++) {
        cin >> page[i];
    }
    
    sort(page.rbegin(), page.rend());
    
    int qIndex = 0;
    for (int k = 1; k <= n; k++) {
        if (page[k - 1] >= k) qIndex = k;
        else break;
    }
    
    cout << qIndex;
    
    return 0;
}