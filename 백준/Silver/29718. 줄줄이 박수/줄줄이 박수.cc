#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> prefix(m + 1, 0);
    for (int i = 0; i < m; i++) {
        prefix[i + 1] = prefix[i];

        for (int j = 0; j < n; j++) {
            prefix[i + 1] += arr[j][i];
        }
    }

    int a;
    cin >> a;

    int ans = 0;
    for (int i = 0; i <= m - a; i++) {
        ans = max(ans, prefix[a + i] - prefix[i]);
    }

    cout << ans;

    return 0;
}