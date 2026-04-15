#include <bits/stdc++.h>

using namespace std;
using llg = long long;

void eratos(vector<bool>& arr, llg n) {
    arr[0] = false;
    arr[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (arr[i]) {
            for (int j = i * i; j < n; j += i) {
                arr[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> primeArr(32769, true);
    eratos(primeArr, 32769);

    llg num;

    while (true) {
        llg count = 0;
        cin >> num;

        if (num == 0) break;

        for (int i = 2; i <= num / 2; i++) {
            if (primeArr[i] && primeArr[num - i]) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}