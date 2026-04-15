#include <bits/stdc++.h>
using namespace std;

const int MAX = 50001;

vector<int> arr[MAX];
int pa[MAX], de[MAX];

void dfs(int n, int p, int d) {
    pa[n] = p, de[n] = d;

    for (int i : arr[n]) {
        if (i != p) dfs(i, n, d + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    dfs(1, 0, 0);

    int m;
    cin >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;

        while (de[u] != de[v]) {
            de[u] > de[v] ? u = pa[u] : v = pa[v];
        }

        while (u != v) {
            u = pa[u], v = pa[v];
        }

        cout << u << '\n';
    }

    return 0;
}