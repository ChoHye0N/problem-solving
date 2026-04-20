#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        map<int, int> mrr;
        int n, m;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;

            mrr[tmp]++;
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;

            cout << (mrr[tmp] >= 1 ? 1 : 0) << '\n';
        }
    }

    return 0;
}