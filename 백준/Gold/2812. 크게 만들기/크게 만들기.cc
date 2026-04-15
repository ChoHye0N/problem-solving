#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, k;
    string num;
    cin >> n >> k >> num;
    
    vector<int> stack;
    
    for (char c : num) {
        while (k > 0 && !stack.empty() && stack.back() < c - '0') {
            stack.pop_back();
            k--;
        }
        stack.push_back(c - '0');
    }
    
    while (k > 0) {
        stack.pop_back();
        k--;
    }
    
    for (int n : stack) {
        cout << n;
    }
    
    return 0;
}