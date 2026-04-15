#include <bits/stdc++.h>
using namespace std;
using v2 = vector<vector<int>>;

string ans = "";

void f(int x, int y, int n, int sum, v2& arr) {
    if (sum == n * n) {
        ans.push_back('1');
        return;
    }
    if (sum == 0) {
        ans.push_back('0');
        return;
    }
    if (n == 1) {
        ans.push_back(sum + '0');
        return;
    }

    int h = n / 2, srr[4] = { 0, };

    for (int i = x; i < x + h; i++) {
        for (int j = y; j < y + h; j++) {
            srr[0] += arr[i][j];
        }
    }
    for (int i = x + h; i < x + n; i++) {
        for (int j = y; j < y + h; j++) {
            srr[1] += arr[i][j];
        }
    }
    for (int i = x; i < x + h; i++) {
        for (int j = y + h; j < y + n; j++) {
            srr[2] += arr[i][j];
        }
    }
    for (int i = x + h; i < x + n; i++) {
        for (int j = y + h; j < y + n; j++) {
            srr[3] += arr[i][j];
        }
    }

    ans.push_back('(');
    f(x, y, h, srr[0], arr);
    f(x, y + h, h, srr[2], arr);
    f(x + h, y, h, srr[1], arr);
    f(x + h, y + h, h, srr[3], arr);
    ans.push_back(')');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    v2 arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < n; j++) {
            arr[i][j] = tmp[j] - '0';
            sum += arr[i][j];
        }
    }

    f(0, 0, n, sum, arr);

    cout << ans;

    return 0;
}