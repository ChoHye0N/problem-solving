#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, idx;
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

vector<int> comb;
vector<vector<int>> combs;

void dfs(int mask){
    if (mask == (1 << 5) - 1){
        combs.push_back(comb);
        return;
    }

    for (int i = 0; i < 5; i++){
        if (mask & (1 << i)) continue;

        comb.push_back(i);
        dfs(mask | (1 << i));
        comb.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++){
        char c;
        cin >> edges[i].u >> edges[i].v >> c;

        edges[i].idx = c - 'A';
    }
    
    map<vector<int>, vector<int>> mstEdgeCnts;
    dfs(0);

    for (int i = 0; i < combs.size(); i++){
        int r[5];
        for (int k = 0; k < 5; k++){
            r[combs[i][k]] = k;
        }

        sort(edges.begin(), edges.end(), [&](auto& a, auto& b){
            return r[a.idx] < r[b.idx];
        });

        vector<int>& cnt = mstEdgeCnts[combs[i]];
        cnt = {0, 0, 0, 0, 0};

        DSU dsu(n);

        for (auto& e : edges){
            if (dsu.unite(e.u, e.v)){
                cnt[e.idx]++;
            }
        }
    }

    for (int i = 0; i < q; i++){
        int univ[5];

        for (int j = 0; j < 5; j++){
            cin >> univ[j];
        }

        vector<int> arr(5);
        for (int j = 0; j < 5; j++){
            arr[j] = j;
        }
        
        sort(arr.begin(), arr.end(), [&](int a, int b){
            return univ[a] < univ[b];
        });

        vector<int>& cnt = mstEdgeCnts[arr];

        long long sum = 0;
        for (int j = 0; j < 5; j++){
            sum += 1LL * cnt[j] * univ[j];
        }

        cout << sum << '\n';
    }

    return 0;
}