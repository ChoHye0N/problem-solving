#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<bool> arr(10001, true);
    arr[0] = false, arr[1] = false;

    for (int i = 2; i < 10001; i++) {
        if (!arr[i]) continue;
        for (int j = i * i; j < 10001; j += i) {
            arr[j] = false;
        }
    }

    int minN = -1, sum = 0;
    for (int i = m; i <= n; i++) {
        if (arr[i] && minN < 0) minN = i;
        if (arr[i]) sum += i;
    }

    if (minN == -1) cout << -1;
    else cout << sum << '\n' << minN;

    return 0;
}