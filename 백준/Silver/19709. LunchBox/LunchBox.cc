#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> neededBoxes(m);
    for (int i = 0; i < m; i++) {
        cin >> neededBoxes[i];
    }

    sort(neededBoxes.begin(), neededBoxes.end());

    int total = 0, count = 0;

    for (int i = 0; i < m; i++) {
        if (total + neededBoxes[i] > n) {
            break;
        }
        total += neededBoxes[i];
        count++;
    }

    cout << count << '\n';
    return 0;
}