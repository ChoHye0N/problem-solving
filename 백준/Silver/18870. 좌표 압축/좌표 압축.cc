#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> coordinate_compression(const vector<int>& arr) {
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

    vector<int> compressed_arr(arr.size());
    for (int i = 0; i < arr.size(); i++)
        compressed_arr[i] = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin();

    return compressed_arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> compressed = coordinate_compression(arr);

    for (int i = 0; i < n - 1; i++)
        cout << compressed[i] << ' ';
    cout << compressed[compressed.size() - 1] << '\n';

    return 0;
}