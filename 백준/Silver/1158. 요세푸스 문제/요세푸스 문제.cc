#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 1; i <= n; i++) {
        arr[i - 1] = i;
    }

    int idx = 0;

    cout << '<';
    while (!arr.empty()) {
        idx = (idx + k - 1) % arr.size();

        cout << arr[idx];
        arr.erase(arr.begin() + idx);

        if (!arr.empty()) {
            cout << ", ";
        }
    }
    cout << ">";

    return 0;
}