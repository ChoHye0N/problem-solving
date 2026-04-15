#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string str, word;
    getline(cin, str);
    getline(cin, word);

    if (str.size() < word.size()) {
        cout << "0";
        return 0;
    }

    int count = 0;
    
    for (int i = 0; i <= str.size() - word.size(); i++) {
        bool match = true;
        
        for (int j = 0; j < word.size(); j++) {
            if (str[i + j] != word[j]) {
                match = false;
                break;
            }
        }
        
        if (match) {
            count++;
            i += word.size() - 1;
        }
    }

    cout << count;
    
    return 0;
}