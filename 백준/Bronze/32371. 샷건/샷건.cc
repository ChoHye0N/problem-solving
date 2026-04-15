#include <bits/stdc++.h>

using namespace std;

bool is_same_str(string &a, string &b){
    return unordered_set<char>(a.begin(), a.end()) == unordered_set<char>(b.begin(), b.end());
}

int main() {
    string input;
    vector<string> keys(4);
    
    for (int i = 0; i < 4; i++) {
        cin >> keys[i];
    }
    cin >> input;

    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 9; j++) {
            string temp = "";

            for (int r = i - 1; r <= i + 1; r++) {
                for (int c = j - 1; c <= j + 1; c++) {
                    temp.push_back(keys[r][c]);
                }
            }

            if (is_same_str(temp, input)) {
                cout << keys[i][j];
                return 0;
            }
        }
    }

    return 0;
}