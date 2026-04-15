#include <bits/stdc++.h>
using namespace std;

vector<int> eratos(vector<bool> &arr){
    vector<int> res;
    
    for (int i = 2; i < arr.size(); i++){
        if (!arr[i]) continue;
        for (int j = i * i; j < arr.size(); j += i){
            arr[j] = false;
        }
        
        res.push_back(i);
    }
    
    return res;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; 
    cin >> t;
    
    vector<bool> parr(100001, true);
    vector<int> prime;
    parr[0] = parr[1] = false;
    
    prime = eratos(parr);
    
    while (t--){
        int n;
        cin >> n;
        
        map<int, int> ans;
        for (int i = 0; i < prime.size();){
            if (n % prime[i] == 0){
                ans[prime[i]]++;
                n /= prime[i];
            }
            else if (n % prime[i] != 0) i++;
            else break;
        }
        
        for (auto &p : ans){
            cout << p.first << ' ' << p.second << '\n';
        }
    }
    
    return 0;
}