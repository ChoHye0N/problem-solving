#include <bits/stdc++.h>
using namespace std;

using llg = long long;

struct Edge{
    int u, v;
    llg w;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;

    int minC = INT_MAX;
    vector<int> cost(n);
    for (int i = 0; i < n; i++){
        cin >> cost[i];
        minC = min(minC, cost[i]);
    }
    
    vector<Edge> adj(p);
    for (int i = 0; i < p; i++){
        int u, v;
        llg c;
        cin >> u >> v >> c;

        u--;
        v--;

        adj[i] = {u, v, cost[u] + cost[v] + c * 2};
    }

    sort(adj.begin(), adj.end(), [&](auto& a, auto& b){
        return a.w < b.w;
    });

    DSU dsu(n);
    llg sum = 0;
    int cnt = 0;
    
    for (Edge e : adj){
        if (dsu.unite(e.u, e.v)){
            sum += e.w;
            if (++cnt == n - 1) break;
        }
    }

    cout << sum + minC;

    return 0;
}