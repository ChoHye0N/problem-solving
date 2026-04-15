#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> rod(n);
    for (int i = 0; i < n; i++){
        cin >> rod[i];
    }
    
    sort(rod.begin(), rod.end());
    
    long long totalLen = accumulate(rod.begin(), rod.end(), 0);
    long long minCost = 0;
    for (int i = 0; i < n - 1; i++){
        totalLen -= rod[i];
        minCost += rod[i] * totalLen;
    }
    
    cout << minCost;
    
    return 0;
}