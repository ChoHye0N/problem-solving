#include <bits/stdc++.h>
using namespace std;

vector<int> stk;

void comb(int a, int b) {
    if (b == 0) {
        for (int i = 0; i < stk.size(); i++) {
            cout << stk[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= a; i++) {
        stk.push_back(i);
        comb(a, b - 1);
        stk.pop_back();
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    comb(n, m);

    return 0;
}