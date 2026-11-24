#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int ans = INT_MAX;
    
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            for (int d1 = 1; d1 < n; d1++){
                for (int d2 = 1; d2 < n; d2++){
                    if (x + d1 + d2 >= n || y - d1 < 0 || y + d2 >= n) continue;

                    int sum[5] = {0};

                    for (int r = 0; r < n; r++){
                        for (int c = 0; c < n; c++){
                            int k;
                            if (r < x) k = (c <= y) ? 0 : 1;
                            else if (r > x + d1 + d2) k = (c < y - d1 + d2) ? 2 : 3;
                            else {
                                int left  = (r <= x + d1) ? y - (r - x) : y - d1 + (r - x - d1);
                                int right = (r <= x + d2) ? y + (r - x) : y + d2 - (r - x - d2);

                                if (c < left) k = (r < x + d1) ? 0 : 2;
                                else if (c > right) k = (r <= x + d2) ? 1 : 3;
                                else k = 4;
                            }

                            sum[k] += arr[r][c];
                        }
                    }

                    ans = min(ans, *max_element(sum, sum + 5) - *min_element(sum, sum + 5));
                }
            }
        }
    }

    cout << ans;

    return 0;
}