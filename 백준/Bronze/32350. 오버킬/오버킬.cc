#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, p;
    cin >> n >> d >> p;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int t = 0, idx = 0;
    while (idx < n) {
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                idx = i;
                break;
            }
        }

        if (idx == -1) break;

        arr[idx] -= d;

        if (arr[idx] <= 0 && idx + 1 < n) {
            arr[idx + 1] -= (-arr[idx] * p) / 100;
        }

        t++;
    }

    cout << t;

    return 0;
}