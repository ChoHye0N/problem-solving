#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int k;
    cin >> k;
    
    const int N = 7500000;
    
    vector<bool> eratos(N, true);
    vector<int> ans(1, 0);
    for (int i = 2; i * i < N; i++){
        if (eratos[i]){
            for (int j = i * 2; j < N + 1; j += i){
                eratos[j] = false;
            }
        }
    }
    
    for (int i = 2; i < eratos.size(); i++){
        if (eratos[i]) ans.push_back(i);
    }
    
    cout << ans[k];
    
    return 0;
}