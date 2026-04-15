#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << n << '\n';

    vector<int> arr;

    if (n % 3 == 0) {
        for (int i = 0; i < n / 3; i++) {
            arr.push_back(3 * i + 1);
            arr.push_back(3 * i + 3);
            arr.push_back(3 * i + 2);
        }
    }
    else {
        arr.push_back(1);

        for (int i = 0; i < n / 3 + 1; i++) {
            if (arr.size() < n) arr.push_back(3 * i + 2);
            if (arr.size() < n) arr.push_back(3 * i + 4);
            if (arr.size() < n) arr.push_back(3 * i + 3);
        }
    }

    for (int p : arr) {
        cout << p << ' ';
    }
    cout << 1;

    return 0;
}