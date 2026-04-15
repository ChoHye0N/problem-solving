#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str, keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    
    while (getline(cin, str)){
        for (int i = 0; i < str.size(); i++){
            if (str[i] == ' '){
                cout << ' ';
                continue;
            }
            
            for (int j = 0; j < keyboard.size(); j++){
                if (str[i] == keyboard[j]){
                    cout << keyboard[j - 1];
                }
            }
        }
        cout << '\n';
    }

    
    return 0;
}