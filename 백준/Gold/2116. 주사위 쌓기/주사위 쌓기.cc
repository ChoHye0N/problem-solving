#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(6));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    int op[6] = { 5, 3, 4, 1, 2, 0 };
    int ans = 0;

    for (int i = 0; i < 6; i++) {
        int top = arr[0][i], sum = 0, maxN = 0;

        for (int idx = 1; idx <= 6; idx++) {
            if (idx == arr[0][op[i]] || idx == top) continue;
            maxN = max(maxN, idx);
        }
        sum += maxN;

        for (int j = 1; j < n; j++) {
            int bottom = -1;
            maxN = 0;

            for (int idx = 0; idx < 6; idx++) {
                if (arr[j][idx] == top) {
                    bottom = top, top = arr[j][op[idx]];
                    break;
                }
            }
            for (int idx = 1; idx <= 6; idx++) {
                if (idx == bottom || idx == top) continue;
                maxN = max(maxN, idx);
            }
            sum += maxN;
        }
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}