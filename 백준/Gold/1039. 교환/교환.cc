#include <bits/stdc++.h>
using namespace std;

int maxN = -1;

void dfs(string s, int n, int cnt, set<pair<string, int>>& visited) {
    if (cnt == n) {
        if (stoi(s) > maxN) maxN = stoi(s);
        return;
    }

    if (visited.count({ s, cnt })) return;
    visited.insert({ s, cnt });

    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (i == 0 && s[j] == '0') continue;
            swap(s[i], s[j]);
            dfs(s, n, cnt + 1, visited);
            swap(s[i], s[j]);
        }
    }
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    set<pair<string, int>> visited;

    dfs(n, k, 0, visited);

    cout << maxN;

    return 0;
}