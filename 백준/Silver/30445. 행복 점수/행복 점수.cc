#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string words;
    getline(cin, words);
    
    long long pos = count(words.begin(), words.end(), 'H') + 
        count(words.begin(), words.end(), 'A') + count(words.begin(), words.end(), 'P') +
        count(words.begin(), words.end(), 'Y'),
        neg = count(words.begin(), words.end(), 'S') + count(words.begin(), words.end(), 'A') + 
        count(words.begin(), words.end(), 'D');
    
    long long ans;
    if (pos == 0 && neg == 0){
        ans = 5000;
    }
    else {
        ans = (pos * 10000 + (pos + neg) / 2) / (pos + neg);
    }
    
    printf("%lld.%02lld", ans / 100, ans % 100);
    
    return 0;
}