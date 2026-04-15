#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);

    stack<int> stk;
    stk.push(1);
    visited[1] = true;

    while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();

        for (int next : graph[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                stk.push(next);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    
    return 0;
}