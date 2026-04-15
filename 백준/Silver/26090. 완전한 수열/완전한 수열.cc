#include <bits/stdc++.h>

using namespace std;

vector<bool> check(1000001, true);
vector<int> primeArr;

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
    
    check[0] = check[1] = false;
    for (int i = 2; i * i < check.size(); i++){
        if (check[i]){
            for (int j = i * i; j < check.size(); j += i){
                check[j] = false;
            }
        }
    }
    
    for (int i = 2; i < check.size(); i++){
        if (check[i]) primeArr.push_back(i);
    }
    
    int ans = 0;
    for (int len : primeArr){
        if (len > n) break;
        
        for (int i = 0; i <= n - len; i++){
            if (check[accumulate(arr.begin() + i, arr.begin() + len + i, 0)]) ans++;
        }
    }
    
    cout << ans;
    
    return 0;
}