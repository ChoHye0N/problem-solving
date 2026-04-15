#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    cin >> b;
    
    vector<string> nums;
    string num;
    
    stringstream ss(a);
    while (ss >> num) {
        nums.push_back(num);
    }
    
    int cnt = 0;
    for (string n : nums) {
        if (n.substr(0, b.size()) == b && n != b) {
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}