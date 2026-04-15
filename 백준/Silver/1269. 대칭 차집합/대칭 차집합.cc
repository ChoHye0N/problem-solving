#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n), brr(m);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    vector<int> a, b;
    set_difference(arr.begin(), arr.end(), brr.begin(), brr.end(), back_inserter(a));
    set_difference(brr.begin(), brr.end(), arr.begin(), arr.end(), back_inserter(b));

    cout << a.size() + b.size();

    return 0;
}