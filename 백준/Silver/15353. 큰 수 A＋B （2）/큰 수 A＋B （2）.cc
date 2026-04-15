#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2, ans = "";
    cin >> s1 >> s2;

    int i = s1.size() - 1, j = s2.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) {
            sum += (s1[i--] - '0');
        }
        if (j >= 0) {
            sum += (s2[j--] - '0');
        }

        carry = sum / 10;
        ans += (sum % 10) + '0';
    }
    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}