#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;

        double avg = 0, ans = 0;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;

            arr[i] = tmp;
            avg += tmp;
        }
        avg /= n;

        for (int i = 0; i < n; i++) {
            if (arr[i] > avg) ans++;
        }

        printf("%.3f%%\n", ans / n * 100);
    }

    return 0;
}