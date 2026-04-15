#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> ropes(n);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }
    
    sort(ropes.begin(), ropes.end());
    
    int maxWeight = 0;
    for (int i = 0; i < n; i++) {
        int weight = ropes[i] * (n - i);
        
        if (weight > maxWeight) {
            maxWeight = weight;
        }
    }
    
    cout << maxWeight;
    
    return 0;
}