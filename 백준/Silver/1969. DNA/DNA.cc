#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    string ans = "";
    int minCount = 0;
    for (int i = 0; i < m; i++){
        map<char, int> freq;
        
        for (int j = 0; j < n; j++){
            freq[arr[j][i]]++;
        }
        
        char bestChar = 'A';
        int bestCount = freq['A'];
        
        for (auto& p : freq){
            if (p.second > bestCount){
                bestChar = p.first;
                bestCount = p.second;
            }
        }
        
        ans += bestChar;
        minCount += n - bestCount;
    }
    
    cout << ans << '\n' << minCount;
    
    return 0;
}