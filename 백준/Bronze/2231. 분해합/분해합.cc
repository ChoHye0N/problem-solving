#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int minN = 0;
    int start = max(1, n - 9 * (int)to_string(n).size());

    for (int i = start; i < n; i++) {
        int sum = i, temp = i;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == n) {
            minN = i;
            break;
        }
    }

    cout << minN << '\n';
    return 0;
}