#include <iostream>
#include <vector>
#include <algorithm>

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
vector<int> lis(vector<int>& arr) {
    vector<int> sub;
    vector<int> sub_idx;
    vector<int> prev(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
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
        lis_arr.push_back(arr[k]);
        k = prev[k];
    }

    reverse(lis_arr.begin(), lis_arr.end());

    return lis_arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> lis_arr = lis(arr);
    cout << lis_arr.size() << "\n";

    for (int num : lis_arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}