#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n && n != 0) {
        vector<double> expenses(n);
        double total = 0.0;

        for (int i = 0; i < n; i++) {
            cin >> expenses[i];
            total += expenses[i];
        }

        double avg = total / n;
        double give = 0.0, take = 0.0;

        for (int i = 0; i < n; i++) {
            double diff = (double)((long)((expenses[i] - avg) * 100.0)) / 100.0;

            if (diff > 0)
                take += diff;
            else
                give -= diff;
        }

        printf("$%.2f\n", max(give, take));
    }

    return 0;
}