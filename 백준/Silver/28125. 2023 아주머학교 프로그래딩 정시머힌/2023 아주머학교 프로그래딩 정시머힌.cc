#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        int cnt = 0;
        string ans = "";
        string a = "acijnot", b = "@[!;^07";


        for (int i = 0; i < str.size(); i++) {
            if (i + 2 < str.size() && str[i] == '\\' && str[i + 1] == '\\' && str[i + 2] == '\'') {
                ans += 'w';
                cnt++;
                i += 2;
            }
            else if (i + 1 < str.size() && str[i] == '\\' && str[i + 1] == '\'') {
                ans += 'v';
                cnt++;
                i++;
            }
            else {
                bool ok = false;

                for (int j = 0; j < 7; j++) {
                    if (str[i] == b[j]) {
                        ans += a[j];
                        cnt++;
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    ans += str[i];
                }
            }
        }

        cout << (cnt * 2 >= ans.size() ? "I don't understand" : ans) << '\n';
    }

    return 0;
}