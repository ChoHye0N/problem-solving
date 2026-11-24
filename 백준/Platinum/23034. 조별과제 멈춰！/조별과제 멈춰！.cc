#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

struct DSU{
    vector<int> p, r;

    DSU(int n) : p(n + 1), r(n + 1){
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

vector<vector<pair<int, int>>> mst;
long long maxW;
bool found;

void dfs(int curr, int prev, int target, long long sum) {
    if (found) return;
    if (curr == target) {
        maxW = sum;
        found = true;
        return;
    }

    for (auto& e : mst[curr]) {
        if (found) return;
        if (e.first == prev) continue;
        dfs(e.first, curr, target, max(sum, 0LL + e.second));
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = {u, v, w};
    }
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a.w < b.w;
    });

    DSU dsu(n);
    mst.assign(n + 1, {});
    long long total = 0;

    for (auto& e : edges){
        if (dsu.unite(e.u, e.v)){
            total += e.w;
            mst[e.u].push_back({e.v, e.w});
            mst[e.v].push_back({e.u, e.w});
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        found = false;
        maxW = 0;
        dfs(a, -1, b, 0LL);

        cout << total - maxW << '\n';
    }

    return 0;
}