#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string formula;
    cin >> formula;
    
    bool isMinus = false;
    string num = "";
    int total = 0;
    
    for (int i = 0; i < formula.size(); i++){
        if (isdigit(formula[i])){
            num.push_back(formula[i]);
        }
        else {
            if (!num.empty()) {
                if (isMinus) total -= stoi(num);
                else total += stoi(num);
                num = "";
            }
            if (formula[i] == '-') isMinus = true;
        }
    }
    
    if (!num.empty()) {
        if (isMinus) total -= stoi(num);
        else total += stoi(num);
    }
    
    cout << total;
    
    return 0;
}