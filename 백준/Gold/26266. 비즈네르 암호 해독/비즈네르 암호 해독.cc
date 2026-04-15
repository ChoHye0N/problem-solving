#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string word, str;
    cin >> word >> str;

    string ans = "";
    int len = word.size();

    for (int i = 0; i < len; i++) {
        int diff = str[i] - word[i];

        if (diff <= 0) diff += 26;
        ans.push_back(diff + 'A' - 1);
    }

    vector<int> arr(len, 0);
    for (int i = 1, j = 0; i < len; i++) {
        while (j > 0 && ans[i] != ans[j]) {
            j = arr[j - 1];
        }
        if (ans[i] == ans[j]) {
            arr[i] = ++j;
        }
    }

    if (len % (len - arr[len - 1]) == 0) {
        cout << ans.substr(0, len - arr[len - 1]);
    }
    else {
        cout << ans;
    }

    return 0;
}