#include <bits/stdc++.h>
using namespace std;

int l, c;

void comb(vector<char>& arr, vector<char>& stk, int n) {
    if (stk.size() == l) {
        int a = 0, b = 0;
        string str = string(stk.begin(), stk.end());

        for (int i = 0; i < l; i++) {
            bool flag = true;

            for (char tmp : "aeiou") {
                if (str[i] == tmp) {
                    flag = false;
                    break;
                }
            }
            flag ?  a++ : b++;
        }

        if (a >= 2 && b >= 1) cout << str << '\n';

        return;
    }

    for (int i = n; i < c; i++) {
        stk.push_back(arr[i]);
        comb(arr, stk, i + 1);
        stk.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c;

    vector<char> arr(c), stk;
    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    comb(arr, stk, 0);

    return 0;
}