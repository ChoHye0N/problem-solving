#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[30] = { 0, };
    for (int i = 0; i < 28; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp - 1]++;
    }

    for (int i = 0; i < 30; i++) {
        if (arr[i] == 0) cout << i + 1 << '\n';
    }

    return 0;
}