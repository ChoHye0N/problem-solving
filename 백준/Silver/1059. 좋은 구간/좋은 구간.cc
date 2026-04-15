#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int sSize, n;
    int lower = 0, upper = 0, count = 0;
    cin >> sSize;

    vector<int> s(sSize);
    for (int i = 0; i < sSize; i++) {
        cin >> s[i];
    }

    cin >> n;

    sort(s.begin(), s.end());

    // 집합 S에 n이 존재하는지 확인
    if (binary_search(s.begin(), s.end(), n)) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < sSize; i++) {
        if (s[i] < n) {
            lower = s[i];
        }
        else if (s[i] > n) {
            upper = s[i];
            break;
        }
    }

    for (int a = lower + 1; a <= n; a++) {
        for (int b = n; b < upper; b++) {
            count++;
        }
    }

    cout << count - 1 << '\n';

    return 0;
}