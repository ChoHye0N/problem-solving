#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str;
    cin >> str;
    
    vector<int> alpha(26, 0);
    for (char s : str) {
        alpha[s - 'A']++;
    }
    
    int oddCount = 0;
    char midS = 0;
    
    for (int i = 0; i < alpha.size(); i++){
        if (alpha[i] % 2 != 0) {
            oddCount++;
            midS = 'A' + i;
        }
        if (oddCount > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
        alpha[i] /= 2;
    }
    
    string ans = "";
    for (int idx = 0; idx < alpha.size(); idx++){
        while (alpha[idx] > 0) {
            ans.push_back('A' + idx);
            alpha[idx]--;
        }
    }
    
    if (midS) ans.push_back(midS);
    
    int start = (midS ? ans.size() - 2 : ans.size() - 1);
    for (int i = start; i >= 0; i--){
        ans.push_back(ans[i]);
    }
    
    cout << ans;
    
    return 0;
}