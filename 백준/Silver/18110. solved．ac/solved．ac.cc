#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> level(n);
    for (int i = 0; i < n; ++i) {
        cin >> level[i];
    }

    sort(level.begin(), level.end());

    int trimCount = n * 0.15 + 0.5;
    int sum = 0;

    for (int i = trimCount; i < n - trimCount; ++i) {
        sum += level[i];
    }

    cout << (int)(sum / (n - 2. * trimCount) + 0.5) << '\n';

    return 0;
}