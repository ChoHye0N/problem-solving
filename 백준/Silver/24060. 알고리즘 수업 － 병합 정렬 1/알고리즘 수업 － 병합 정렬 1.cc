#include <bits/stdc++.h>
using namespace std;
using v1 = vector<int>;

int cnt = 0, ans = -1, k;

void mg(v1& arr, int s, int m, int e) {
    int i = s, j = m + 1, t = 0;

    v1 tmp(e - s + 1);
    while (i <= m && j <= e) {
        if (arr[i] <= arr[j]) tmp[t++] = arr[i++];
        else tmp[t++] = arr[j++];
    }
    while (i <= m) {
        tmp[t++] = arr[i++];
    }
    while (j <= e) {
        tmp[t++] = arr[j++];
    }

    i = s, t = 0;
    while (i <= e) {
        arr[i++] = tmp[t++];
        cnt++;
        if (cnt == k) {
            ans = arr[i - 1];
        }
    }
}

void mg_sort(v1& arr, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mg_sort(arr, s, m);
        mg_sort(arr, m + 1, e);
        mg(arr, s, m, e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> k;

    v1 arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mg_sort(arr, 0, arr.size() - 1);

    cout << ans;

    return 0;
}