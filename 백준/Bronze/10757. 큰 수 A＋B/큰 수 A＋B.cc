#include <bits/stdc++.h>

using namespace std;

string addNum(string a, string b, int carry) {
    if (a.empty() && b.empty() && carry == 0) return "";
    
    int x = 0, y = 0;
    
    if (!a.empty()) {
        x = a.back() - '0';
        a.pop_back();
    }
    if (!b.empty()) {
        y = b.back() - '0';
        b.pop_back();
    }

    int sum = x + y + carry;
    char digit = (sum % 10) + '0';

    return addNum(a, b, sum / 10) + digit;
}


int main() {
    string a, b;
    cin >> a >> b;
    
    cout << addNum(a, b, 0);
    
    return 0;
}