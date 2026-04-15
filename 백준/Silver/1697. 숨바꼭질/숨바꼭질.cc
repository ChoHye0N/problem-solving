#include <bits/stdc++.h>
using namespace std;

void bfs(int s, int e, vector<int>& arr) {
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == e) return;

        int ops[3] = { curr + 1, curr - 1, curr * 2 };

        for (int i = 0; i < 3; i++) {
            int nx = ops[i];

            if (nx < 0 || nx >= arr.size()) continue;

            if (arr[nx] == 0) {
                q.push(nx);
                arr[nx] = arr[curr] + 1;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(1e5 + 1, 0);

    bfs(n, k, arr);

    cout << arr[k];

    return 0;
}