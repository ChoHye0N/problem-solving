#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    double ans = arr[0];
    for (int i = 1; i < n; i++) {
        ans += arr[i] / 2;
    }

    printf("%.6f", ans);

    return 0;
}