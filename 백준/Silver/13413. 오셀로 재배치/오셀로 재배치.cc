#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string str1, str2;
        cin >> n >> str1 >> str2;

        int ans = 0, diff1 = 0, diff2 = 0;

        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[i]) {
                if (str1[i] == 'W') diff1++;
                else diff2++;
            }
        }

        cout << max(diff1, diff2) << '\n';
    }

    return 0;
}