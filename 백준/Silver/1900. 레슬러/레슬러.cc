#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(4, 0));
    for (int i = 0; i < n; i++) {
        arr[i][0] = i + 1;
        cin >> arr[i][1] >> arr[i][2];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][1] + arr[j][1] * arr[i][2] > arr[j][1] + arr[i][1] * arr[j][2]) {
                arr[i][3]++;
            }
            else arr[j][3]++;
        }
    }

    sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
        return a[3] > b[3];
        });

    for (int i = 0; i < n; i++) {
        cout << arr[i][0] << '\n';
    }

    return 0;
}