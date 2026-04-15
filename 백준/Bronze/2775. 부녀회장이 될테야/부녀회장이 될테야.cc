#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    for (int t = 0; t < tc; t++) {
        int k, n;
        cin >> k >> n;

        vector<vector<int>> apt(k + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            apt[0][i] = i;

        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
 
        cout << apt[k][n] << '\n';
    }

    return 0;
}