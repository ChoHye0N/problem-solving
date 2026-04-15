#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str;
    cin >> n >> str;

    int ans = 0;

    while (n--) {
        string tmp;
        cin >> tmp;

        bool found = false;

        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] != str[0]) continue;

            for (int j = i + 1; j < tmp.size(); j++) {
                if (tmp[j] != str[1]) continue;

                bool ok = true;

                for (int k = 2; k < str.size(); k++) {
                    int next = i + (j - i) * k;

                    if (next >= tmp.size() || tmp[next] != str[k]) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    found = true;
                    break;
                }
            }

            if (found) break;
        }

        if (found) ans++;
    }

    cout << ans;

    return 0;
}