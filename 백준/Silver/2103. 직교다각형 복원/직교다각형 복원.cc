#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;

    unordered_map<int, vector<int>> pointX;
    unordered_map<int, vector<int>> pointY;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pointX[x].push_back(y);
        pointY[y].push_back(x);
    }

    for (auto& [x, yList] : pointX) {
        sort(yList.begin(), yList.end());
        for (int j = 0; j + 1 < yList.size(); j += 2)
            sum += yList[j + 1] - yList[j];
    }

    for (auto& [y, xList] : pointY) {
        sort(xList.begin(), xList.end());
        for (int j = 0; j + 1 < xList.size(); j += 2)
            sum += xList[j + 1] - xList[j];
    }

    cout << sum << '\n';
    return 0;
}