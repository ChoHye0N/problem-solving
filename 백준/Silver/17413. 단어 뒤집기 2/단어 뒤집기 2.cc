#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    
    int i = 0;
    while(i < str.length()) {
        if(str[i] == '<') {
            cout << str[i++];
            while(str[i] != '>') {
                cout << str[i++];
            }
            cout << str[i++];
        }
        else {
            string word;
            while(i < str.length() && str[i] != ' ' && str[i] != '<') {
                word += str[i++];
            }
            reverse(word.begin(), word.end());
            cout << word;
            
            if (i < str.length() && str[i] == ' ') {
                cout << str[i++];
            }
        }
    }
    
    return 0;
}