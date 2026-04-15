#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

int isCollinear(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.y - p1.y) * (p3.x - p2.x) == (p3.y - p2.y) * (p2.x - p1.x);
}

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> lineLen(3);
    vector<Point> points(3);

    for (int i = 0; i < 3; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (int i = 0; i < 3; i++) {
        lineLen[i] = distance(points[i], points[(i + 1) % 3]);
    }

    sort(lineLen.begin(), lineLen.end());

    if (isCollinear(points[0], points[1], points[2]))  cout << fixed << setprecision(1) << -1.0 << '\n';

    else cout << fixed << setprecision(16) << (lineLen[1] + lineLen[2]) * 2 - (lineLen[0] + lineLen[1]) * 2 << '\n';

    return 0;
}