#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[100001];
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        arr[tmp] = i;
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (arr[i] < arr[i - 1]) ans++;
    }

    cout << ans;

    return 0;
}