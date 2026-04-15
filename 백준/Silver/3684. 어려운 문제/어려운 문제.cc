#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> x(t);
    for (int i = 0; i < t; i++) {
        cin >> x[i];
    }

    bool flag = false;
    int a, b;

    for (int ai = 0; ai < 10001; ai++) {
        for (int bi = 0; bi < 10001; bi++) {
            int count = 0;

            for (int i = 0; i < t - 1; i++) {
                int num = (ai * x[i] + bi) % 10001;
                if (x[i + 1] == (ai * num + bi) % 10001) count++;
                else break;
            }

            if (count == t - 1) {
                flag = true;
                a = ai;
                b = bi;
                break;
            }
        }
        if (flag) break;
    }

    for (int i = 0; i < t; i++) {
        cout << (a * x[i] + b) % 10001 << '\n';
    }

    return 0;
}