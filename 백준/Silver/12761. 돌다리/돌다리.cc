#include <bits/stdc++.h>
using namespace std;

int a, b, n, m;
const int MAX = 1e5;

void bfs(vector<int>& arr) {
    queue<int> q;
    q.push(n);
    arr[n]++;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int dx[6] = {a, b, -a, -b, 1, -1}, nx = 0;

        for (int i = 0; i < 6; i++) {
            int nx = curr + dx[i];

            if (nx >= 0 && nx <= MAX && arr[nx] == 0) {
                q.push(nx);
                arr[nx] = arr[curr] + 1;
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = curr * dx[i];

            if (nx >= 0 && nx <= MAX && arr[nx] == 0) {
                q.push(nx);
                arr[nx] = arr[curr] + 1;
            }
        }
    }
}

int main() {
    cin >> a >> b >> n >> m;

    vector<int> arr(MAX + 1, 0);
    
    bfs(arr);

    cout << arr[m] - 1;

    return 0;
}