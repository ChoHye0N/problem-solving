#include <iostream>
#include <vector>

using llg = long long;

using namespace std;

llg ccw(const vector<llg>& p1, const vector<llg>& p2, const vector<llg>& p3) {
    return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p3[0] - p1[0]) * (p2[1] - p1[1]);
}

int main() {
    vector<vector<llg>> points(4, vector<llg>(2, 0));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            cin >> points[i][j];

    llg d1 = ccw(points[0], points[1], points[2]);
    llg d2 = ccw(points[0], points[1], points[3]);
    llg d3 = ccw(points[2], points[3], points[0]);
    llg d4 = ccw(points[2], points[3], points[1]);

    bool intersect = (d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0);
    bool intersect2 = (d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0);

    if (intersect && intersect2)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';

    return 0;
}