#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e4;

struct Path {
    int p, op;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        queue<int> q;
        vector<bool> visited(10000, false);
        vector<Path> arr(10000);

        q.push(a);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == b) break;

            int dx[] = {
                (curr * 2) % MOD,
                (curr == 0) ? 9999 : curr - 1,
                (curr % 1000) * 10 + (curr / 1000),
                (curr % 10) * 1000 + (curr / 10)
            };
            char op[] = { 'D', 'S', 'L', 'R' };

            for (int i = 0; i < 4; i++) {
                int nx = dx[i];

                if (!visited[nx]) {
                    visited[nx] = true;
                    arr[nx] = { curr, op[i] };
                    q.push(nx);
                }
            }
        }

        string ans = "";
        int top = b;

        while (top != a) {
            ans += arr[top].op;
            top = arr[top].p;
        }
        reverse(ans.begin(), ans.end());

        cout << ans << '\n';
    }

    return 0;
}