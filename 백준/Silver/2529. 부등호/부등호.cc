#include <bits/stdc++.h>
using namespace std;

string maxS = "0", minS = "999999999";
bool check[9] = { false, };

void dfs(vector<char>& arr, vector<int>& stk, int n, int d) {
    if (d == n + 1) {
        string sn = "";

        for (int i = 0; i < n + 1; i++) {
            sn += (stk[i] + '0');
        }

        if (sn > maxS) {
            maxS = sn;
        }
        if (sn < minS) {
            minS = sn;
        }

        return;
    }

    for (int i = 0; i < 10; i++) {
        if (d > 0) {
            if (arr[d - 1] == '<' && !(stk[d - 1] < i)) continue;
            if (arr[d - 1] == '>' && !(stk[d - 1] > i)) continue;
        }

        if (!check[i]) {
            stk.push_back(i);
            check[i] = true;

            dfs(arr, stk, n, d + 1);

            stk.pop_back();
            check[i] = false;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<char> arr(n);
    vector<int> stk;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dfs(arr, stk, n, 0);

    cout << maxS << '\n' << minS;

    return 0;
}