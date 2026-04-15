#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, l;
    cin >> n >> k >> l;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (x + y + z >= k && x >= l && y >= l && z >= l) {
            arr.push_back(x);
            arr.push_back(y);
            arr.push_back(z);
        }
    }

    cout << arr.size() / 3 << '\n';
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}