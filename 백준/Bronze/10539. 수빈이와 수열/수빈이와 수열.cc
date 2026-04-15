#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    llg sum = 0;
    vector<llg> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        arr[i] = arr[i] * (i + 1) - sum;
        sum += arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}