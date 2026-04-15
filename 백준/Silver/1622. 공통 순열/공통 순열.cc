#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    while (getline(cin, a), getline(cin, b)) {
        int freq[26] = {0};
        vector<char> sortedStr;
        
        for (char c : a) {
            freq[c - 'a']++;
        }
        
        for (char c : b) {
            if (freq[c - 'a'] > 0) {
                sortedStr.push_back(c);
                freq[c - 'a']--;
            }
        }
        
        sort(sortedStr.begin(), sortedStr.end());
        
        for (char c : sortedStr) {
            cout << c;
        }
        
        cout << '\n';
    }
    return 0;
}