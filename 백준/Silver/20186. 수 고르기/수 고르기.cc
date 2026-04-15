#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    
    sort(arr.rbegin(), arr.rend());
    
    vector<int> selects;
    int score = 0;
    
    for (int i = 0; i < k; i++){
        selects.push_back(arr[i][1]);
    }
    
    sort(selects.begin(), selects.end());
    
    for (int i = 0; i < k; i++){
        score += arr[i][0] - i;
    }
    
    cout << score << '\n';
    
    return 0;
}