#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<int> arr(n);
    unordered_map<int, int> mrr, firstIdx;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mrr[arr[i]]++;

        if (firstIdx.find(arr[i]) == firstIdx.end()) {
            firstIdx[arr[i]] = i;
        }
    }

    stable_sort(arr.begin(), arr.end(), [&](int a, int b) {
        if (mrr[a] != mrr[b]) return mrr[a] > mrr[b];
        return firstIdx[a] < firstIdx[b];
        });

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}