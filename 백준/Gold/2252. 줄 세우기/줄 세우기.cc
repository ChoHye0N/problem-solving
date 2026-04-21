#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> inN(n + 1, 0);
    vector<vector<int>> arr(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        inN[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inN[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (int v : arr[u]) {
            inN[v]--;

            if (inN[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int p : ans) {
        cout << p << ' ';
    }

    return 0;
}