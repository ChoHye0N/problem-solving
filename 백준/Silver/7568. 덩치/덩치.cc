#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> pInfo(n, vector<int>(2));
    vector<int> sizeRank(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> pInfo[i][0] >> pInfo[i][1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && pInfo[i][0] < pInfo[j][0] && pInfo[i][1] < pInfo[j][1])
                sizeRank[i]++;
        }
    }

    for (int num : sizeRank) {
        cout << num << ' ';
    }

    return 0;
}