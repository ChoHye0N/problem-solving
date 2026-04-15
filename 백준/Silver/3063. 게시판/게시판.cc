#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int arr[8], sq1, sq2;
        
        for (int i = 0; i < 8; i++) {
            cin >> arr[i];
        }

        sq1 = (arr[2] - arr[0]) * (arr[3] - arr[1]);
        sq2 = max(0, min(arr[2], arr[6]) - max(arr[0], arr[4])) *
            max(0, min(arr[3], arr[7]) - max(arr[1], arr[5]));

        cout << sq1 - sq2 << '\n';
    }

    return 0;
}