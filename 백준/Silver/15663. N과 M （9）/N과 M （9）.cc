#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> stk, arr;
map<vector<int>, bool> used;

void dfs(int mask, int d){
    if (d == m){
        used[stk] = true;
        return;
    }

    for (int i = 0; i < n; i++){
        if (mask & (1 << i)) continue;

        stk.push_back(arr[i]);
        dfs(mask | (1 << i), d + 1);
        stk.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dfs(0, 0);

    for (auto& p : used){
        for (int pp : p.first){
            cout << pp << ' ';
        }
        cout << '\n';
    }

    return 0;
}