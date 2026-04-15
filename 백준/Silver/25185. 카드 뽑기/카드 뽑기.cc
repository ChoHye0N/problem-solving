#include <bits/stdc++.h>
using namespace std;

bool f1(vector<string> &arr){
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 4; j++){
            for (int k = j + 1; k < 4; k++){
                char c1 = arr[i].back(), c2 = arr[j].back(), c3 = arr[k].back();
                
                if (c1 == c2 && c2 == c3){
                    vector<int> v;
                    
                    v.push_back(arr[i][0] - '0');
                    v.push_back(arr[j][0] - '0');
                    v.push_back(arr[k][0] - '0');
                    sort(v.begin(), v.end());
                    
                    if (v[0] + 1 == v[1] && v[1] + 1 == v[2]) return true;
                }
            }
        }
    }
    
    return false;
}

bool f2(vector<string> &arr){
    map<string, int> m;
    
    for (int i = 0; i < 4; i++){
        m[arr[i]]++;
    }
    for (auto &tmp : m){
        if (tmp.second >= 3) return true;
    }
    
    return false;
}

bool f3(vector<string> &arr){
    map<string, int> m;
    
    for (int i = 0; i < 4; i++){
        m[arr[i]]++;
    }
    for (auto &tmp : m){
        if (tmp.second != 2) return false;
    }
    
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--){
        vector<string> card(4);
        for (int i = 0; i < 4; i++){
            cin >> card[i];
        }
        sort(card.begin(), card.end());
        
        if (f1(card) || f2(card) || f3(card)){
            cout << ":)\n";
        }
        else{
            cout << ":(\n";
        }
    }
    
    return 0;
}