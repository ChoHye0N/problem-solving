#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> threePoints(3, vector<int>(2, 0));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            cin >> threePoints[i][j];

    int d = (threePoints[1][0] - threePoints[0][0]) * (threePoints[2][1] - threePoints[0][1])
        - (threePoints[1][1] - threePoints[0][1]) * (threePoints[2][0] - threePoints[0][0]);
    

    if (d > 0) cout << 1 << '\n';
    else if (d == 0) cout << 0 << '\n';
    else if (d < 0) cout << -1 << '\n';

    return 0;
}