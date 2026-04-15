#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<vector<long long>> dp;
vector<vector<long long>> matrix;

long long travel(int mask, int pos, int n) {
    /* Use a bitmask */

    // Visited all city
    if (mask == (1 << n) - 1)
        return matrix[pos][0];
    // Return pre-calculated values
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    long long min_cost = numeric_limits<long long>::max();

    // Trying to visit all city
    for (int i = 0; i < n; i++)
        if (!(mask & (1 << i)) && matrix[pos][i] < numeric_limits<long long>::max()) {
            long long temp = matrix[pos][i] + travel(mask | (1 << i), i, n);
            min_cost = min(temp, min_cost);
        }
        
    return dp[mask][pos] = min_cost;
}

int main() {
    int n;
    cin >> n;

    matrix.resize(n, vector<long long>(n));
    dp.resize(1 << n, vector<long long>(n, -1));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            matrix[i][j] = (i == j || temp == 0) ? numeric_limits<int>::max() : temp;
        }
    
    cout << travel(1, 0, n) << "\n";
    return 0;
}