#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int len = str.size();
    string word = "", check1 = "aeiouh";
    vector<string> check2 = { "c", "j", "n", "m", "t", "s", "l", "d", "qu" }, ans;

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') word.push_back(str[i]);

        if (str[i] == ' ' || str[i] == '-' || i == len - 1) {
            if (!word.empty()) {
                ans.push_back(word);
                word = "";
            }
        }
        else if (str[i] == '\'') {
            i++;
            bool flag1 = false, flag2 = false;
            string tmp = "";

            while (i < len && str[i] != '-' && str[i] != ' ') {
                tmp.push_back(str[i++]);
            }

            for (string s : check2) {
                if (word == s) {
                    flag1 = true;
                    break;
                }
            }
            for (char c : check1) {
                if (tmp[0] == c) {
                    flag2 = true;
                    break;
                }
            }

            if (flag1 && flag2) {
                ans.push_back(word);
                ans.push_back(tmp);
            }
            else {
                ans.push_back(word + tmp);
            }
            word = "";
        }
    }

    cout << ans.size();

    return 0;
}