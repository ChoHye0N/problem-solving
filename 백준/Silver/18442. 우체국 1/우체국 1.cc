#include <bits/stdc++.h>
using namespace std;
using llg = long long;

vector<llg> arr, pos, ansPos;
llg ans = LLONG_MAX;
int v, p;
llg l;

void rfs(int d, int s){
    if (d == p){
        llg sum = 0;
        
        for (int i = 0; i < v; i++){
            llg minN = LLONG_MAX;
            
            for (int j = 0; j < p; j++){
                minN = min({minN, abs(arr[i] - pos[j]), l - abs(arr[i] - pos[j])});
            }
            
            sum += minN;
        }
        
        if (ans > sum){
            ans = sum;
            ansPos = pos;
        }
        
        return;
    }
    
    for (int i = s; i < v; i++){
        pos.push_back(arr[i]);
        rfs(d + 1, i + 1);
        pos.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> p >> l;
    
    arr.resize(v);
    for (int i = 0; i < v; i++){
        cin >> arr[i];
    }
    
    pos.clear(), ansPos.clear();
    
    rfs(0, 0);
    
    sort(ansPos.begin(), ansPos.end());
    
    cout << ans << '\n';
    for (int i = 0; i < p; i++){
        cout << ansPos[i] << ' ';
    }
    
    return 0;
}