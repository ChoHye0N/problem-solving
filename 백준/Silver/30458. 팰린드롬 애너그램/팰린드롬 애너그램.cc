#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;

    cin >> n >> str;

    vector<int> arr(26, 0);
    for (int i = 0; i < n; i++) {
        if (n % 2 != 0 && i == n / 2) continue;
        arr[str[i] - 'a']++;
    }

    int odd = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) odd++;
    }

    cout << (odd == 0 ? "Yes" : "No");

    return 0;
}