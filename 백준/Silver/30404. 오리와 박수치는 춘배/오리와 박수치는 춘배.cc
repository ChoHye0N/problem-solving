#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    int ans = 0, curr = -1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > curr) {
            ans++;
            curr = arr[i] + k;
        }
    }

    cout << ans;

    return 0;
}