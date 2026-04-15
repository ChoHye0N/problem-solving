#include <bits/stdc++.h>
using namespace std;

using llg = long long;

int f_k(vector<llg>& prefix, vector<llg>& prefixPow, int k) {
    int res = -1;
    llg maxV = -1;

    for (int i = 0; i < prefix.size() - k; i++) {
        llg sum = prefix[i + k] - prefix[i];
        llg v = (prefixPow[i + k] - prefixPow[i]) * k - sum * sum;

        if (v > maxV) {
            maxV = v;
            res = i + 1;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector <llg> prefix(n + 1, 0), prefixPow(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        llg tmp;
        cin >> tmp;

        prefix[i] = prefix[i - 1] + tmp;
        prefixPow[i] = prefixPow[i - 1] + tmp * tmp;
    }

    for (int i = 1; i <= n; i++) {
        cout << f_k(prefix, prefixPow, i) << '\n';
    }

    return 0;
}