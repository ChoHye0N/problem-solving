#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> arr(n, vector<int>(2));
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];
        arr[i][1] = i; 
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        p[arr[i][1]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }

    return 0;
}