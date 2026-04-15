#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(MAX, 0);
    deque<int> dq;

    arr[n] = 1;
    dq.push_back(n);


    while (!dq.empty()) {
        int curr = dq.front();
        dq.pop_front();

        if (curr == k) break;

        int dx1 = curr * 2;
        if (dx1 >= 0 && dx1 < MAX && arr[dx1] == 0) {
            arr[dx1] = arr[curr];
            dq.push_front(dx1);
        }

        int dx2[2] = { curr - 1, curr + 1 };
        for (int i = 0; i < 2; i++) {
            int nx = dx2[i];

            if (nx >= 0 && nx < MAX && arr[nx] == 0) {
                dq.push_back(nx);
                arr[nx] = arr[curr] + 1;
            }
        }
    }

    cout << arr[k] - 1;

    return 0;
}