#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int maxS = 0, minE = 100000;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;

        maxS = max(maxS, s);
        minE = min(minE, e);
    }

    cout << max(0, maxS - minE);

    return 0;
}