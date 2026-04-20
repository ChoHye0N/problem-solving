#include <bits/stdc++.h>
using namespace std;

int bs(vector<int>& arr, int n) {
    int s = 0, e = arr.size() - 1;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (arr[mid] == n) {
            return 1;
        }
        else if (arr[mid] > n) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        vector<int> arr, brr;
        int n, m;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;

            arr.push_back(tmp);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int tmp;
            cin >> tmp;

            brr.push_back(tmp);
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < m; i++) {
            cout << bs(arr, brr[i]) << '\n';
        }
    }

    return 0;
}