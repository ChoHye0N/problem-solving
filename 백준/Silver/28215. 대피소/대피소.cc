#include <bits/stdc++.h>
using namespace std;

int n, k, ans = INT_MAX;
vector<int> stk;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(vector<vector<int>>& arr, int d) {
    if (stk.size() == k) {
        int maxD = 0;

        for (int i = 0; i < n; i++) {
            int minD = INT_MAX;

            for (int j = 0; j < stk.size(); j++) {
                int x = arr[stk[j]][0], y = arr[stk[j]][1];
                minD = min(minD, dist(arr[i][0], arr[i][1], x, y));
            }
            maxD = max(maxD, minD);
        }
        ans = min(ans, maxD);

        return;
    }

    for (int i = d; i < n; i++) {
        stk.push_back(i);
        dfs(arr, i + 1);
        stk.pop_back();
    }
}

int main() {
    cin >> n >> k;

    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    dfs(arr, 0);

    cout << ans;

    return 0;
}