#include <bits/stdc++.h>
using namespace std;

int ets(vector<bool>& arr, int n, int a) {
    int res = 0, cnt = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (arr[j]) {
                arr[j] = false;
                res = j;
                cnt++;
            }
            if (cnt >= a) return res;
        }
        if (cnt >= a) return res;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<bool> arr(n + 1, true);
    arr[0] = arr[1] = false;

    cout << ets(arr, n, k);

    return 0;
}