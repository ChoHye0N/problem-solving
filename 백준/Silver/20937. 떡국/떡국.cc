#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<int, int> arr;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }

    vector<pair<int, int>> sArr(arr.begin(), arr.end());
    sort(sArr.begin(), sArr.end(), [](auto& a, auto& b) {
        return a.second > b.second;
        });

    cout << sArr[0].second;

    return 0;
}