#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int ans, point = 0;
    cin >> ans;

    for (int i = 1; i < n; i++) {
        int tmp;
        cin >> tmp;

        point += ans * tmp;
        ans += tmp;
    }

    cout << point;

    return 0;
}