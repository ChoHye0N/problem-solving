#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> cost(n);
        for (int i = 0; i < n; i++) {
            cin >> cost[i];
        }

        vector<vector<int>> adj(n + 1);
        vector<int> inNode(n + 1, 0);

        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            inNode[v]++;
        }

        int w;
        cin >> w;

        vector<int> dp(n + 1, 0);
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (inNode[i] == 0) {
                q.push(i);
                dp[i] = cost[i - 1];
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u] + cost[v - 1]);
                inNode[v]--;

                if (inNode[v] == 0) {
                    q.push(v);
                }
            }
        }

        cout << dp[w] << '\n';
    }

    return 0;
}