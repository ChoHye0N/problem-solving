#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(10001, 0);
    for (int i = 0; i < n; i++) {
        short tmp;
        cin >> tmp;
        arr[tmp]++;
    }
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i]) {
            for (int j = 0; j < arr[i]; j++) {
                cout << i << '\n';
            }
        }
    }

    return 0;
}