#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> arr(5);
    for (int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    cout << accumulate(arr.begin(), arr.end(), 0) / 5 << '\n';
    cout << arr[2];
    
    return 0;
}