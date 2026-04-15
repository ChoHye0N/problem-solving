#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        arr[i] = { a, b, c, d, 0 };
    }

    sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
        if (a[1] != b[1]) return a[1] > b[1];
        else if (a[2] != b[2]) return a[2] > b[2];
        return a[3] > b[3];
        });

    int r = 1;
    arr[0][4] = 1;


    if (arr[0][0] == k) {
        cout << 1;
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i][1] == arr[i - 1][1] && arr[i][2] == arr[i - 1][2] &&
            arr[i][3] == arr[i - 1][3]) {
            arr[i][4] = r;
        }
        else {
            r = i + 1;
            arr[i][4] = r;
        }

        if (arr[i][0] == k) {
            cout << arr[i][4];
            return 0;
        }
    }

    return 0;
}