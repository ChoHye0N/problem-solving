#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cows(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cows[i][j];
        }
    }

    vector<int> mid;

    for (int i = 0; i < n; i++) {
        sort(cows[i].begin(), cows[i].end());
        mid.push_back(cows[i][n / 2]);
    }

    sort(mid.begin(), mid.end());
    int perfect_cow = mid[n / 2];

    cout << perfect_cow << '\n';

    return 0;
}