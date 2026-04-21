#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int t;
        cin >> t;

        if (t == 0) break;

        vector<int> arr(t);
        for (int i = 0; i < t; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        bool ok = (t > 1 ? true : false);

        for (int i = 1; i < t; i++) {
            if (arr[i] - arr[i - 1] > 200) {
                ok = false;
                break;
            }
        }

        if ((1422 - arr[t - 1]) * 2 > 200) {
            ok = false;
        }

        cout << (ok ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }

    return 0;
}