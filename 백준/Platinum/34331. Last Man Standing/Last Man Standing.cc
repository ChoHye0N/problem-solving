#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

struct DSU{
    vector<int> p, r; 

    DSU(int n) : p(n), r(n){
        for (int i = 0; i < n; i++){
            p[i] = i;
        }
    }

    int find(int x){
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b){
        a = find(a), b = find(b);

        if (a == b) return false;

        if (r[a] < r[b]) swap(a, b);

        p[b] = a;
        if (r[a] == r[b]) r[a]++;

        return true;
    }
};

int n, k;
vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> matches;

void dfs(int x){
    visited[x] = true;

    for (int y : adj[x]){
        if (visited[y]) continue;

        dfs(y);
        matches.push_back({x, y});
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<Edge> edges;
    unordered_map<int, long long> nodeSum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int w;
            cin >> w;

            nodeSum[i] += w;

            if (i >= j) continue;
            edges.push_back({i, j, w});
            
        }
    }
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a.w > b.w;
    });

    DSU dsu(n);
    adj.assign(n, {});
    visited.assign(n, false);
    int cnt = 0;
    long long sum = 0;

    for (auto& e : edges){
        if (cnt >= n - k) break;

        if (dsu.unite(e.u, e.v)){
            sum += e.w;
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
            cnt++;
        }
    }

    for (int i = 0; i < n; i++){
        if (!visited[i]) dfs(i);
    }

    cout << sum << '\n';
    for (auto& e : matches){
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }

    return 0;
}