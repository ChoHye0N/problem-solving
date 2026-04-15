#include <bits/stdc++.h>

using namespace std;
using llg = long long;

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
    
    llg total = 1, speed = 1;
    for (int i = n - 2; i >= 0; i--){
        if (arr[i] > speed) speed++;
        else if (arr[i] < speed) speed = arr[i];
        total += speed;
    }
    
    cout << total;
    
    return 0;
}