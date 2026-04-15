#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;

            arr[i][j] = tmp + d * (i + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    bool ok = true;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[j][i] <= arr[j - 1][i]) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }

    cout << (ok ? "YES" : "NO");

    return 0;
}