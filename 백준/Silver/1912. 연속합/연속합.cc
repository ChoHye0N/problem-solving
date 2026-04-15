#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    cin >> n >> num;

    int curr = num, ans = num;
    
    for (int i = 1; i < n; i++) {
        cin >> num;

        curr = max(num, curr + num);
        ans = max(ans, curr);
    }

    cout << ans;

    return 0;
}