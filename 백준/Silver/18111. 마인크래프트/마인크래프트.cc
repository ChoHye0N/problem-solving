#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, b;
    cin >> n >> m >> b;

    int maxH = 0, minH = INT_MAX;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            maxH = max(maxH, arr[i][j]);
            minH = min(minH, arr[i][j]);
        }
    }

    int ansT = INT_MAX, ansH = 0;

    for (int h = minH; h <= maxH; h++) {
        int outputB = 0, inputB = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int diff = arr[i][j] - h;

                if (diff > 0) inputB += diff;
                else if (diff < 0) outputB -= diff;
            }
        }

        if (inputB + b >= outputB) {
            int currT = inputB * 2 + outputB;

            if (currT <= ansT) {
                ansT = currT;
                ansH = h;
            }
        }
    }

    cout << ansT << ' ' << ansH;

    return 0;
}