#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 0) {
        cout << (m == 0 ? 0 : -1);
        return 0;
    }

    vector<int> arr(n), visited(5001, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    m = 2000 + m;
    queue<int> q;
    q.push(2000);
    visited[2000] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == m) {
            cout << visited[curr];
            return 0;
        }

        for (int i = 0; i < arr.size(); i++) {
            int nx = curr + arr[i];

            if (nx >= 0 && nx <= 5000 && visited[nx] == -1) {
                q.push(nx);
                visited[nx] = visited[curr] + 1;
            }
        }
    }

    cout << -1;

    return 0;
}