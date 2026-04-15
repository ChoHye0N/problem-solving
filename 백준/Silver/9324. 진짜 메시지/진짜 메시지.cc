#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    cin.ignore();
    
    for (int i = 0; i < t; i++){
        int flag = 1;
        string str;
        getline(cin, str);
        
        vector<int> alpha(26, 0);
        for (int idx = 0; idx < str.size(); idx++){
            int alphaIdx = str[idx] - 'A';
            alpha[alphaIdx]++;
            
            if (alpha[alphaIdx] % 3 == 0){
                if (str[idx] == str[idx + 1]){
                    idx++;
                }
                else if (str[idx] != str[idx + 1]){
                    flag = 0;
                    break;
                }
            }
        }
        
        if (flag) cout << "OK" << '\n';
        else cout << "FAKE" << '\n';
    }
    
    return 0;
}