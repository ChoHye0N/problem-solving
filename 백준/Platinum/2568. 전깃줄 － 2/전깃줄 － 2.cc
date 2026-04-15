#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int binary_search(const vector<int>& arr, int num) {
    int start = 0, end = arr.size();

    while (start < end) {
        int mid = (start + end) / 2;
        if (arr[mid] < num)
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

/* LIS: Longest Increasing Subsequence */
vector<int> lis(vector<pair<int, int>>& arr) {
    vector<int> sub;
    vector<int> sub_idx;
    vector<int> prev(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i].first;
        int idx = binary_search(sub, num);

        if (idx == sub.size()) {
            sub.push_back(num);
            sub_idx.push_back(i);
        }
        else {
            sub[idx] = num;
            sub_idx[idx] = i;
        }

        if (idx > 0)
            prev[i] = sub_idx[idx - 1];

    }

    vector<int>lis_arr;
    int k = sub_idx.back();

    while (k >= 0) {
        lis_arr.push_back(arr[k].first);
        k = prev[k];
    }

    reverse(lis_arr.begin(), lis_arr.end());

    // Find the element to remove from the original list
    unordered_set<int> lis_set(lis_arr.begin(), lis_arr.end());
    vector<int> to_remove;

    for (const pair<int, int>& p : arr) {
        if (lis_set.find(p.first) == lis_set.end()) {
            to_remove.push_back(p.first);
        }
    }
    sort(to_remove.begin(), to_remove.end());

    return to_remove;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> wires(n, {0, 0});

    for (int i = 0; i < n; i++) {
        cin >> wires[i].first >> wires[i].second;
    }

    sort(wires.begin(), wires.end(), [](const pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    vector<int> lis_arr = lis(wires);
    cout << lis_arr.size() << "\n";

    for (int num : lis_arr) {
        cout << num << "\n";
    }

    return 0;
}