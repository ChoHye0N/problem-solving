#include <bits/stdc++.h>
using namespace std;
using llg = long long;
using Mx = vector<vector<llg>>;

const int MOD = 1e9 + 7, N = 8;

Mx multi_mx(Mx& a, Mx& b) {
    Mx res(N, vector<llg>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return res;
}

Mx pow_mx(Mx& m, llg n) {
    Mx res(N, vector<llg>(N, 0));

    for (int i = 0; i < N; i++) {
        res[i][i] = 1;
    }

    while (n > 0) {
        if (n % 2 != 0) res = multi_mx(res, m);

        m = multi_mx(m, m);
        n /= 2;
    }

    return res;
}

int main()
{
    llg d;
    cin >> d;

    Mx arr = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0} };

    arr = pow_mx(arr, d);

    cout << arr[0][0];

    return 0;
}