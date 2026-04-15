#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> prefix(1000001, 0), count(1000001, 0);

    prefix[1] = 2;
    for (int i = 2; i <= 500000; i++) {
        prefix[i] = prefix[i - 1] + (i + 1);
    }

    for (int i = 1; i <= 500000; i++) {
        for (int j = i - 1; j > 0; j--) {
            int sum = prefix[i] - prefix[j] + (j + 1);
            if (sum > 1000001 - 1) break;
            count[sum]++;
        }
    }

    int n;
    while (cin >> n && n != 0) {
        if (n == 1) {
            cout << 0 << '\n';
        }
        else {
            cout << count[n] + 1 << '\n';
        }
    }

    return 0;
}