#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() 
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    llg ans = 0, sum = 0;
    while (true){
        sum = 0;
        
        for (int i = 1; i < n - 1; i++){
            if (arr[i - 1] + arr[i + 1] < arr[i] * 2){
                int mi = arr[i] - (arr[i - 1] + arr[i + 1]) / 2;
                arr[i] -= mi;
                sum += mi;
            }
        }
        
        if (sum == 0) break;
        ans += sum;
    }
    
    cout << ans;
    
    return 0;
}