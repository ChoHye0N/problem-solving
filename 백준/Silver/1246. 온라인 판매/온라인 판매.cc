#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int maxProfit = 0, price = 0;
    for (int i = 0; i < m; i++) {
        int profit = arr[i] * min(n, m - i);
        
        if (profit > maxProfit) {
            maxProfit = profit;
            price = arr[i];
        }
    }
    
    cout << price << ' ' << maxProfit;
    
    return 0;
}