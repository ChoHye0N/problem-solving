#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> ans(n);
    for (int t = 0; t < 2; t++) {
        vector<vector<int>> check(m + 1);

        for (int i = 1; i <= n; i++) {
            while (true) {
                int tmp;
                cin >> tmp;

                if (tmp == -1) break;

                check[tmp].push_back(i);
            }
        }

        for (int i = 0; i < m; i++) {
            if (check[i + 1].size() <= arr[i] && arr[i] > 0) {
                for (int p : check[i + 1]) {
                    ans[p - 1].push_back(i + 1);
                }
                arr[i] -= check[i + 1].size();
            }
            else {
                arr[i] -= check[i + 1].size();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i].empty()) {
            cout << "망했어요\n";
        }
        else {
            sort(ans[i].begin(), ans[i].end());

            for (int x : ans[i]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}