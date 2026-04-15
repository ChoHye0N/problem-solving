#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;

            arr[i][j] = abs(arr[i][j] - tmp);
        }
    }

    vector<int> maxArr(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxArr[i] = max(maxArr[i], arr[j][i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;

        ans += maxArr[tmp - 1];
    }

    cout << ans;

    return 0;
}