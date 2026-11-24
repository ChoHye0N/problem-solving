#include <bits/stdc++.h>
using namespace std;

struct Chef{
    int p, c;
};

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

vector<vector<int>> adj;
vector<pair<int, int>> res;

void dfs(int curr, int parent){
    for (int next : adj[curr]){
        if (next == parent) continue;
        dfs(next, curr);
        res.push_back({curr, next});
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Chef> chefs(n);
    for (int i = 0; i < n; i++){
        cin >> chefs[i].p >> chefs[i].c;
    }

    vector<Edge> edges;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int pp = abs(chefs[i].p - chefs[j].p);
            int cc = chefs[i].c + chefs[j].c;
            edges.push_back({i, j, cc / pp});
        }
    }

    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a.w > b.w;
    });

    DSU dsu(n);
    adj.assign(n, {});
    long long sum = 0;
    int cnt = 0;

    for (auto& e : edges){
        if (dsu.unite(e.u, e.v)){
            sum += e.w;
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
            
            if (++cnt == n - 1) break;
        }
    }

    dfs(0, -1);

    cout << sum << '\n';
    for (auto& p : res){
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }

    return 0;
}