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
    sort(arr.rbegin(), arr.rend());
    
    int h = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] >= i + 1){
            h = i + 1;
        }
        else{
            break;
        }
    }
    
    cout << h;
    
    return 0;
}