#include <bits/stdc++.h>
using namespace std;

const int SHIFT = 10000, MAX = 40000;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 0) {
        cout << (m == 0 ? 0 : -1);
        return 0;
    }

    vector<int> arr(n), visited(MAX + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    m = SHIFT + m;
    queue<int> q;
    q.push(SHIFT);
    visited[SHIFT] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == m) {
            cout << visited[curr];
            return 0;
        }

        for (int i = 0; i < arr.size(); i++) {
            int nx = curr + arr[i];

            if (nx >= 0 && nx <= MAX && visited[nx] == -1) {
                q.push(nx);
                visited[nx] = visited[curr] + 1;
            }
        }
    }

    cout << -1;

    return 0;
}