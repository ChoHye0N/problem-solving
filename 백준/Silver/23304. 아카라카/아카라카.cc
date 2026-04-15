#include <bits/stdc++.h>

using namespace std;

bool isPalin(string &str, int s, int e){
    if (s >= e) return true;
    if (str[s] != str[e]) return false;
    return isPalin(str, s + 1, e - 1);
}

bool isAkaraka(string &str, int s, int e) {
    if (s >= e) return true;
    if (!isPalin(str, s, e)) return false;

    int half = (e - s + 1) / 2;

    if (!isAkaraka(str, s, s + half - 1)) return false;
    if (!isAkaraka(str, e - half + 1, e)) return false;

    return true;
}

int main() 
{
    string str;
    cin >> str;
    
    cout << ( isAkaraka(str, 0, str.size() - 1) ? "AKARAKA" : "IPSELENTI");
    
    return 0;
}