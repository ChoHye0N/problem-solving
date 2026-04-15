#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    string stk = "";
    stk.push_back(str[n - 1]);

    for (int i = 2; i <= str.size(); i++) {
        stk.push_back(str[str.size() - i]);
        sort(stk.begin(), stk.end());
        
        if (stk == "AA" || stk == "GT" || stk == "AC") stk = "A";
        else if (stk == "AG" || stk == "CC") stk = "C";
        else if (stk == "CG" || stk == "TT") stk = "T";
        else if (stk == "TA" || stk == "TC" || stk == "GG"
                 || stk == "CT" || stk == "AT") stk = "G";
    }

    cout << stk;
    return 0;
}
