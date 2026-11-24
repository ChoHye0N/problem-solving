#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;

    bool operator<(const Edge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    }
};

struct DSU {
    vector<int> p, r;

    DSU(int n) : p(n), r(n, 0) {
        for (int i = 0; i < n; i++){
            p[i] = i;
        }
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

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

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][j] == 'Y') {
                edges.push_back({i, j});
            }
        }
    }

    if (edges.size() < m) {
        cout << -1 << '\n';
        return 0;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<int> deg(n, 0);
    vector<Edge> unused;
    int selected = 0;

    for (Edge& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            deg[e.u]++;
            deg[e.v]++;
            selected++;
        }
        else {
            unused.push_back(e);
        }
    }

    if (selected != n - 1) {
        cout << -1 << '\n';
        return 0;
    }

    for (Edge& e : unused) {
        if (selected == m) break;
        
        deg[e.u]++;
        deg[e.v]++;
        selected++;
    }

    for (int i = 0; i < n; i++) {
        cout << deg[i] << ' ';
    }

    return 0;
}