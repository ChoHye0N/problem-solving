#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    unordered_map<char, int> umap;
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        umap[tmp]++;
    }

    char a;
    cin >> a;

    cout << umap[a];

    return 0;
}