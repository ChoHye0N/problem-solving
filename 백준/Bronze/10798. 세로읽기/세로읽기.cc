#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> arr(5);
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int maxN = 0;
    for (int i = 0; i < 5; i++) {
        maxN = max(maxN, (int)arr[i].size());
    }

    for (int i = 0; i < maxN; i++) {
        for (int j = 0; j < 5; j++) {
            if (i >= arr[j].size()) continue;
            cout << arr[j][i];
        }
    }

    return 0;
}