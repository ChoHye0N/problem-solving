#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, k;
    cin >> n >> l >> k;

    vector<pair<int, int>> arr(n);
    int ans = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
        });

    for (int i = 0; i < n; i++) {
        int p1 = arr[i].first, p2 = arr[i].second;

        if (cnt >= k) break;

        if (p2 <= l) {
            ans += 140;
            cnt++;
        }
        else if (p1 <= l) {
            ans += 100;
            cnt++;
        }
    }

    cout << ans;

    return 0;
}