#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end(), [](pair<int, int>& near, pair<int, int>& front) {
        if (near.second == front.second)
            return near.first < front.first;
        return near.second < front.second;
    });

    for (const auto& p : points) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}