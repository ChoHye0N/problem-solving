#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string str;
    cin >> str;
    
    int ans, idx, m = 0;
    for (int i = 0; i < 13; i++){
        if (str[i] == '*'){
            idx = i;
            continue;
        }
        if (i % 2 != 0){
            m += (str[i] - '0') * 3;
        }
        else m += str[i] - '0';
    }
    
    int weight = (idx % 2 == 0 ? 1 : 3);
    for (int i = 0; i < 10; i++){
        if ((m + i * weight) % 10 == 0){
            ans = i;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}