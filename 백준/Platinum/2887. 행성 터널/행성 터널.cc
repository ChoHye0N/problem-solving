#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int f_find(vector<int>& p, int n) {
    if (p[n] == n) return n;
    return p[n] = f_find(p, p[n]);
}

void f_union(vector<int>& p, vector<int>& r, int a, int b) {
    a = f_find(p, a), b = f_find(p, b);

    if (a == b) return;

    if (r[a] < r[b]) p[a] = b;
    else {
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> xrr(n), yrr(n), zrr(n);
    for (int i = 0; i < n; i++) {
        cin >> xrr[i] >> yrr[i] >> zrr[i];
    }

    vector<pair<int, int>> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) {
        x[i] = { xrr[i], i };
        y[i] = { yrr[i], i };
        z[i] = { zrr[i], i };
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    vector<int> u, v, w;
    for (int i = 1; i < n; i++) {
        u.push_back(x[i].second), v.push_back(x[i - 1].second), w.push_back(x[i].first - x[i - 1].first);
        u.push_back(y[i].second), v.push_back(y[i - 1].second), w.push_back(y[i].first - y[i - 1].first);
        u.push_back(z[i].second), v.push_back(z[i - 1].second), w.push_back(z[i].first - z[i - 1].first);
    }

    vector<int> idx(w.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b){
        return w[a] < w[b];
        });

    vector<int> p(n), r(n, 0);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    llg total = 0;
    for (int i = 0; i < idx.size(); i++) {
        if (f_find(p, u[idx[i]]) != f_find(p, v[idx[i]])) {
            f_union(p, r, u[idx[i]], v[idx[i]]);
            total += w[idx[i]];
        }
    }

    cout << total << '\n';
}