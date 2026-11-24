#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, c;
};

struct DSU{
    vector<int> p, r;

    DSU(int n) : p(n + 1), r(n + 1){
        for (int i = 1; i <= n; i++){
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

int n, m, k;
vector<Edge> edges;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    edges.assign(m, {});
    for (int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].c;
    }
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a.c < b.c;
    });

    DSU dsu(n), dsu0(n), dsu1(n), dm(n);
    int comp1 = n;

    for (auto& e : edges){
        if (e.c == 1 && dsu1.unite(e.u, e.v)){
            comp1--;
        }
    }

    int minZ = comp1 - 1, maxZ = 0;

    for (auto& e : edges){
        if (e.c == 0 && dsu0.unite(e.u, e.v)){
            maxZ++;
        }
    }

    if (k < minZ || k > maxZ){
        cout << "no solution";
        return 0;
    }

    for (auto& e : edges){
        if (e.c == 1) {
            dm.unite(e.u, e.v);
        }
    }

    vector<Edge> must;
    for (auto& e : edges){
        if (e.c == 0 && dm.unite(e.u, e.v)){
            must.push_back(e);
        }
    }

    vector<Edge> res;
    for (auto& e : must){
        dsu.unite(e.u, e.v);
        res.push_back(e);
    }
    for (auto& e : edges){
        if (e.c == 0 && res.size() < k && dsu.unite(e.u, e.v)){
            res.push_back(e);
        }
    }
    for (auto& e : edges){
        if (e.c == 1 && dsu.unite(e.u, e.v)){
            res.push_back(e);
        }
    }

    if (res.size() != n - 1){
        cout << "no solution";
        return 0;
    }

    for (auto& e : res){
        cout << e.u << ' ' << e.v << ' ' << e.c << '\n';
    }

    return 0;
}