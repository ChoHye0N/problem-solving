#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        string str, check1 = "";
        cin >> str;

        set<char> check2;
        int idx = 0;
        
        check1 += str[0];
        check2.insert(str[0]);

        for (int i = 1; i < str.size(); i++) {
            check2.insert(str[i]);

            if (check1[idx] != str[i]) {
                check1 += str[i];
                idx++;
            }
        }

        if (check1.size() == check2.size()) ans++;
    }

    cout << ans;

    return 0;
}