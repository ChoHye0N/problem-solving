#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(101, vector<int>(101, 0));
    for (int t = 0; t < n; t++) {
        int a, b;
        cin >> a >> b;

        for (int i = a; i < a + 10; i++) {
            for (int j = b; j < b + 10; j++) {
                arr[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (arr[i][j] == 1) ans++;
        }
    }

    cout << ans;

    return 0;
}