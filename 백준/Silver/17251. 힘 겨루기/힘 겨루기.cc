#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> maxL(n), maxR(n);
    maxL[0] = arr[0];
    maxR[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++) {
        if (maxL[i - 1] > arr[i]) maxL[i] = maxL[i - 1];
        else maxL[i] = arr[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        if (maxR[i + 1] > arr[i]) maxR[i] = maxR[i + 1];
        else maxR[i] = arr[i];
    }

    int r = 0, b = 0;
    for (int i = 1; i < n; i++) {
        if (maxL[i - 1] > maxR[i]) r++;
        else if (maxL[i - 1] < maxR[i]) b++;
    }

    if (r > b) cout << 'R';
    else cout << (r < b ? 'B' : 'X');

    return 0;
}