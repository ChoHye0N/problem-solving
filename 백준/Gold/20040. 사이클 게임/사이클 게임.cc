#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        int root = u;
        while (root != parent[root]) {
            root = parent[root];
        }

        while (u != root) {
            int next = parent[u];
            parent[u] = root;
            u = next;
        }

        return root;
    }

    bool union_sets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v])
                parent[root_v] = root_u;
            else if (rank[root_u] < rank[root_v])
                parent[root_u] = root_v;
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            return true;
        }
        return false;
    }
};

int kruskal_algorithm(int n, const vector<pair<int, int>>& edges) {
    UnionFind uf(n);
    int play_count = 1;

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (!uf.union_sets(u, v)) return play_count;
        play_count++;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({ u, v });
    }

    int min_cost = kruskal_algorithm(n, edges);
    cout << min_cost << endl;

    return 0;
}