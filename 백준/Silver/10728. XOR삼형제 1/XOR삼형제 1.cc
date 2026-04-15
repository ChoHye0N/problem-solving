#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> ans;

        for (int i = 0; i < (1 << n); i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp.push_back(j + 1);
                }
            }

            bool flag = true;
            for (int x = 0; x < temp.size(); x++) {
                for (int y = x + 1; y < temp.size(); y++) {
                    for (int z = y + 1; z < temp.size(); z++) {
                        if ((temp[x] ^ temp[y] ^ temp[z]) == 0) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (!flag) break;
            }

            if (flag && temp.size() > ans.size()) {
                ans = temp;
            }
        }

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}