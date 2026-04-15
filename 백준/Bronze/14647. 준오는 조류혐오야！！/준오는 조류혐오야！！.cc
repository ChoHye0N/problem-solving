#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> rows(n, 0), cols(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string tmp;
            cin >> tmp;

            for (char c : tmp) {
                if (c == '9') {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
    }

    int maxR = *max_element(rows.begin(), rows.end());
    int maxC = *max_element(cols.begin(), cols.end());

    if (maxR >= maxC){
        cout << accumulate(rows.begin(), rows.end(), 0) - maxR;
    }
    else {
        cout << accumulate(cols.begin(), cols.end(), 0) - maxC;
    }

    return 0;
}