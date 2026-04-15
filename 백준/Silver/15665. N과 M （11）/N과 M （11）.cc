#include <bits/stdc++.h>
using namespace std;

void dfs(int d, int m, vector<int> &arr, vector<int> &ans){
    if (d == m){
        for (int x : ans){
            cout << x << ' ';
        }
        cout << '\n';
        
        return;
    }
    
    for (int i = 0; i < arr.size(); i++){
        ans.push_back(arr[i]);
        dfs(d + 1, m, arr, ans);
        ans.pop_back();
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    set<int> sarr;
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        
        sarr.insert(tmp);
    }
    
    vector<int> arr(sarr.begin(), sarr.end()), ans;
    
    dfs(0, m, arr, ans);
    
    return 0;
}