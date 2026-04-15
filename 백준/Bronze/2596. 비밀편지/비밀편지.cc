#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    string str;
    cin >> n >> str;
    
    string arr[8] = {"000000", "001111", "010011", 
        "011100", "100110", "101001", "110101", "111010"};
    
    string w = "", ans = "";
    bool flag = true;
    
    for (int i = 0; i < str.size() && flag; i++){
        w.push_back(str[i]);
        
        if ((i + 1) % 6 == 0 && i != 0){
            for (int j = 0; j < 8; j++){
                if (w == arr[j]){
                    ans.push_back(j + 'A');
                    w = "";
                    break;
                }
                else if (j == 7){
                    for (int k = 0; k < 8; k++){
                        int diff = 0;
                        
                        for (int idx = 0; idx < 6; idx++){
                            if (w[idx] != arr[k][idx]) diff++;
                        }
                        
                        if (diff < 2){
                            ans.push_back(k + 'A');
                            w = "";
                            break;
                        }
                        else if (k == 7){
                            ans = to_string(i / 6 + 1);
                            flag = false;
                        }
                    }
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}