#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        swap(arr[a - 1], arr[b - 1]);
    }

    for (int i : arr) {
        cout << i << ' ';
    }

    return 0;
}