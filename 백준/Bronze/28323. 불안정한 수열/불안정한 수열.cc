#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int count = 1;
    for (int i = 1; i < n; i++){
        if ((arr[i - 1] + arr[i]) % 2 == 0) continue;
        else count++;
    }
    
    cout << count;
    
    return 0;
}