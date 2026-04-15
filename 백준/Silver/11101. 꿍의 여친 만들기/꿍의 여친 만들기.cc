#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        string str1, str2;
        cin >> str1 >> str2;

        map<string, int> mrr;
        string key = "", val = "";

        for (int i = 0; i < str1.size(); i++) {
            key += str1[i];

            if (str1[i + 1] == ':') {
                i++;

                while (str1[i] != ',' && i < str1.size()) {
                    val += str1[++i];
                }

                mrr[key] = stoi(val);
                key = "";
                val = "";
            }
        }

        string tmp = "";
        vector<int> c1, c2;

        for (int i = 0; i < str2.size(); i++) {
            tmp += str2[i];

            if (str2[i + 1] == '&') {
                c1.push_back(mrr[tmp]);
                tmp = "";
                i++;
            }
            else if (str2[i + 1] == '|' || i == str2.size() - 1) {
                c1.push_back(mrr[tmp]);
                c2.push_back(*max_element(c1.begin(), c1.end()));
                c1.clear();
                tmp = "";
                i++;
            }
        }

        cout << *min_element(c2.begin(), c2.end()) << '\n';
    }

    return 0;
}