#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) arr.push_back(i);
    }

    cout << (k <= arr.size() ? arr[k - 1] : 0);

    return 0;
}