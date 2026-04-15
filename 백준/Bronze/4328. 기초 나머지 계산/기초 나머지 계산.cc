#include <bits/stdc++.h>

using namespace std;

string to_base(int num, int base) {
    if (num == 0) return "0";
    
    string result;
    while (num > 0) {
        result += (char)(num % base + '0');
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() 
{
    while (true) {
        int b;
        string strP, strM;
        cin >> b;
        
        if (b == 0) break;
        
        cin >> strP >> strM;
        
        int m = 0;
        for (char c : strM) {
            m = m * b + (c - '0');
        }
        
        int rem = 0;
        for (char c : strP) {
            rem = (rem * b + (c - '0')) % m;
        }
        
        cout << to_base(rem, b) << '\n';
    }
    
    return 0;
}