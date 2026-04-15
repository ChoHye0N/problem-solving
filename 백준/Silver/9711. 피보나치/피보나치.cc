#include <iostream>

using namespace std;
using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        llg p, q;
        cin >> p >> q;

        if (p == 1 || p == 2) {
            cout << "Case #" << i << ": " << 1 % q << "\n";
            continue;
        }

        // Space Complexity: O(1)
        llg prev1 = 1, prev2 = 1, curr = 0;
        for (int j = 3; j <= p; j++) {
            curr = (prev1 + prev2) % q;
            prev1 = prev2;
            prev2 = curr;
        }

        cout << "Case #" << i << ": " << curr << "\n";
    }

    return 0;
}