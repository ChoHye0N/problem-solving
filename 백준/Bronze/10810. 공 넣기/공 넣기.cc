#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int j = a - 1; j < b; j++) {
            arr[j] = c;
        }
    }

    for (int i : arr) {
        cout << i << ' ';
    }

    return 0;
}