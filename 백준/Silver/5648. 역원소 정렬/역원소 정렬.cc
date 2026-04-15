#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        reverse(tmp.begin(), tmp.end());
        arr[i] = stoll(tmp);
    }

    sort(arr.begin(), arr.end());

    for (long long num : arr) {
        cout << num << '\n';
    }

    return 0;
}