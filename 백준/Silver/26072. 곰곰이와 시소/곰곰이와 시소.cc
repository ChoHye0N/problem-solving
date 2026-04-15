#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, len;
    cin >> n >> len;

    vector<pair<double, double>> ckn(n);
    for (int i = 0; i < n; i++) {
        cin >> ckn[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> ckn[i].second;
    }

    int t = 100;
    double s = 0, e = len;

    while (t--) {
        double mid = s + (e - s) / 2;
        double lSum = 0, rSum = 0;

        for (int i = 0; i < n; i++) {
            if (ckn[i].first < mid) lSum += ckn[i].second * (mid - ckn[i].first);
            else rSum += ckn[i].second * (ckn[i].first - mid);
        }

        if (lSum > rSum) e = mid;
        else s = mid;
    }

    cout << fixed << setprecision(10) << s;

    return 0;
}