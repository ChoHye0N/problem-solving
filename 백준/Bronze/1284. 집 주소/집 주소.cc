#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> ans;

    while (true) {
        string str;
        cin >> str;

        if (str == "0") break;

        int sum = 0;
        for (char s : str) {
            if (s == '1') sum += 2;
            else if (s == '0') sum += 4;
            else sum += 3;
        }

        ans.push_back(sum + str.size() + 1);
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << '\n';
        cout << ans[i];
    }

    return 0;
}