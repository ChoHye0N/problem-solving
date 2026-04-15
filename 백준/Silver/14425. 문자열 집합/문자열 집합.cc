#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    unordered_map<string, int> words;
    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        
        words[temp] = 1;
    }
    
    int count = 0;
    for (int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        
        if (words.find(temp) != words.end()) count++;
    }
    
    cout << count;
    
    return 0;
}