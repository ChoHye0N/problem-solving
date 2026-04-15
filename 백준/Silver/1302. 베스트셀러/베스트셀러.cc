#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    unordered_map<string, int> arr;
    for (int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        
        arr[tmp]++;
    }
    
    string word = "";
    int ans = 0;
    for (auto p : arr){
        if (ans < p.second || (ans == p.second && p.first < word)){
            ans = p.second;
            word = p.first;
        };
    }
    
    cout << word;
    
    return 0;
}