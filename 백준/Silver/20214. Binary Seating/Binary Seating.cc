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
    sort(arr.begin(), arr.end());
    
    double ans = 0.;
    for (int i = 1; i <= arr[n - 1]; i++){
        double tmp = 1.;
        for (int j = 0; j < n; j++){
            if (arr[j] >= i){
                tmp *= 0.5;
            }
        }
        ans += 1. - tmp;
    }
    
    printf("%.5f", ans);
    
    return 0;
}