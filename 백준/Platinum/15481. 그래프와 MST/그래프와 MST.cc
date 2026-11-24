#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w, id;
};

struct DSU{
    vector<int> p, r;

    DSU(int n) : p(n + 1, 0), r(n + 1, 0){
        for (int i = 1; i < n + 1; i++){
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

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].id = i;
    }

    vector<Edge> sorted = edges;
    sort(sorted.begin(), sorted.end(), [](auto& a, auto& b){
        return a.w < b.w;
    });

    DSU dsu(n);
    long long sum = 0;

    vector<bool> inMst(m, false);
    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto& e : sorted){
        if (dsu.unite(e.u, e.v)){
            sum += e.w;
            inMst[e.id] = true;

            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }
    }

    int LOG = 1;
    while ((1 << LOG) <= n) LOG++;

    vector<vector<int>> up(LOG, vector<int>(n + 1, 0)), mx(LOG, vector<int>(n + 1, 0));
    vector<int> depth(n + 1, -1);

    for (int s = 1; s <= n; s++){
        if (depth[s] != -1) continue;

        depth[s] = 0;
        up[0][s] = s;
        mx[0][s] = 0;

        queue<int> q;
        q.push(s);

        while (!q.empty()){
            int x = q.front();
            q.pop();

            for (auto& p : adj[x]){
                int y = p.first, w = p.second;

                if (depth[y] != -1) continue;

                depth[y] = depth[x] + 1;
                up[0][y] = x;
                mx[0][y] = w;
                q.push(y);
            }
        }
    }

    for (int k = 1; k < LOG; k++){
        for (int v = 1; v <= n; v++){
            int mid = up[k - 1][v];
            
            up[k][v] = up[k - 1][mid];
            mx[k][v] = max(mx[k - 1][v], mx[k - 1][mid]);
        }
    }

    auto pathMax = [&](int a, int b){
        int res = 0;

        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++){
            if (diff & (1 << k)){
                res = max(res, mx[k][a]);
                a = up[k][a];
            }
        }

        if (a == b) return res;

        for (int k = LOG - 1; k >= 0; k--){
            if (up[k][a] != up[k][b]){
                res = max({res, mx[k][a], mx[k][b]});
                a = up[k][a];
                b = up[k][b];
            }
        }

        return max({res, mx[0][a], mx[0][b]});
    };

    for (int i = 0; i < m; i++){
        if (inMst[i]){
            cout << sum << '\n';
        }
        else{
            cout << sum - pathMax(edges[i].u, edges[i].v) + edges[i].w << '\n';
        }
    }

    return 0;
}