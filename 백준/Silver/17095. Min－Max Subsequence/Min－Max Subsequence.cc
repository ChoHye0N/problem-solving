#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    int maxN = 0, minN = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > maxN) maxN = arr[i];
        if (arr[i] < minN) minN = arr[i];
    }

    int diff = maxN - minN;
    if (diff == 0) {
        cout << 1;
        return 0;
    }

    int s = 0, e = 0, len = INT_MAX;
    multiset<int> ms;

    while (e < n) {
        ms.insert(arr[e]);

        while (s <= e && (*ms.rbegin() - *ms.begin()) == diff) {
            len = min(len, e - s + 1);
            auto it = ms.find(arr[s]);
            ms.erase(it);
            s++;
        }

        e++;
    }

    cout << len;

    return 0;
}