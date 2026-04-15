#include <bits/stdc++.h>
using namespace std;
using llg = long long;
using Mx = vector<vector<llg>>;

const int MOD = 1e9 + 7;
int t, n, d;

Mx multi_mx(Mx& a, Mx& b) {
    Mx res(n, vector<llg>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return res;
}

Mx pow_mx(Mx& m, llg k) {
    Mx res(n, vector<llg>(n, 0));

    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }

    while (k > 0) {
        if (k % 2 != 0) res = multi_mx(res, m);
        m = multi_mx(m, m);
        k /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t >> n >> d;

    vector<Mx> mMap(t, Mx(n, vector<llg>(n, 0)));
    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            int u, v, c;
            cin >> u >> v >> c;

            mMap[i][--u][--v] = c;
        }
    }

    Mx cc = mMap[0];
    for (int i = 1; i < t; i++) {
        cc = multi_mx(cc, mMap[i]);
    }

    Mx ans = pow_mx(cc, d / t);
    for (int i = 0; i < d % t; i++) {
        ans = multi_mx(ans, mMap[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}