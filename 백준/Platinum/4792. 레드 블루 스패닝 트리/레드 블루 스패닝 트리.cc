#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v;
    char c;
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

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true){
        int n, m, k;
        cin >> n >> m >> k;

        if (!n && !m && !k) break;

        vector<Edge> edges(m);
        for (int i = 0; i < m; i++){
            cin >> edges[i].c >> edges[i].u >> edges[i].v;
        }

        sort(edges.begin(), edges.end(), [](auto& a, auto& b){
            return a.c < b.c;
        });

        DSU dsuB(n), dsuR(n);
        int minB = n - 1, maxB = 0;
        int bCnt = 0;

        for (auto& e : edges){
            if (dsuB.unite(e.u, e.v)){
                if (e.c == 'B') bCnt++;
            }
        }
        maxB = bCnt;

        sort(edges.begin(), edges.end(), [](auto& a, auto& b){
            return a.c > b.c;
        });

        bCnt = 0;
        for (auto& e : edges){
            if (dsuR.unite(e.u, e.v)){
                if (e.c == 'B') bCnt++;
            }
        }
        minB = bCnt;

        if (k >= minB && k <= maxB) {
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }

    return 0;
}