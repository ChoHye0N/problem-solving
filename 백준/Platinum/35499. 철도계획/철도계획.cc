#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

struct DSU{
    vector<pair<int, int>> p;   // {parent, cycle_count}
    vector<int> r; 

    DSU(int n) : p(n + 1), r(n + 1){
        for (int i = 1; i <= n; i++){
            p[i] = {i, 0};
        }
    }

    int find(int x){
        if (p[x].first == x) return x;
        return p[x].first = find(p[x].first);
    }

    bool unite(int a, int b){
        a = find(a), b = find(b);

        if (a == b){
            if (p[a].second == 0) {
                p[a].second++;
                return true;
            }
            else{
                return false;
            }
        } 

        if (p[a].second + p[b].second > 1) return false;

        if (r[a] < r[b]) swap(a, b);

        p[b].first = a;
        p[a].second += p[b].second;
        
        if (r[a] == r[b]) r[a]++;

        return true;
    }
};

int n, m;
vector<Edge> edges;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    edges.assign(m, {});
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = {u, v, w};
    }
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a.w > b.w;
    });

    DSU dsu(n);
    long long sum = 0;

    for (auto& e : edges){
        if (dsu.unite(e.u, e.v)){
            sum += e.w;
        }
    }

    cout << sum;

    return 0;
}