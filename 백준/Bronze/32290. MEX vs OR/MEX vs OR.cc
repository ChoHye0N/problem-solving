#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;

    set<int> arr;
    for (int i = a; i <= b; i++) {
        arr.insert(i | x);
    }

    int ans = 1001;
    for (int i = 0; i <= 1000; i++) {
        if (arr.find(i) == arr.end()) {
            ans = min(ans, i);
        }
    }

    cout << ans;

    return 0;
}