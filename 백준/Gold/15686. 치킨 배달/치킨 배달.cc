#include <bits/stdc++.h>
using namespace std;

int n, m, ans = INT_MAX;
vector<pair<int, int>> stk;

int dist(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

void dfs(vector<pair<int, int>>& hPos, vector<pair<int, int>>& cPos, int d) {
    if (stk.size() == m) {
        int sumD = 0;

        for (int i = 0; i < hPos.size(); i++) {
            int minD = INT_MAX;

            for (int j = 0; j < m; j++) {
                minD = min(minD, dist(hPos[i].first, hPos[i].second, stk[j].first, stk[j].second));
            }

            sumD += minD;
        }

        ans = min(ans, sumD);

        return;
    }

    for (int i = d; i < cPos.size(); i++) {
        stk.push_back(cPos[i]);
        dfs(hPos, cPos, i + 1);
        stk.pop_back();
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<pair<int, int>> hPos, cPos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            
            if (tmp == 1) {
                hPos.push_back({ i, j });
            }
            else if (tmp == 2) {
                cPos.push_back({ i, j });
            }
        }
    }

    dfs(hPos, cPos, 0);

    cout << ans;

    return 0;
}