#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n), block;
    int ans = 1, cnt = 1;

    cin >> arr[0];
    for (int i = 1; i < n; i++) {
        cin >> arr[i];

        if (arr[i] == arr[i - 1]) cnt++;
        else {
            block.push_back(cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    block.push_back(max(ans, cnt));

    for (int i = 0; i < block.size() - 1; i++) {
        ans = max(ans, block[i] + block[i + 1]);
    }

    cout << ans;

    return 0;
}