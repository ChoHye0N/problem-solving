#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cnt[10] = {0}, place = 1;

    while (place <= n) {
        int before = n / (place * 10);
        int after = n % place;
        int curr = (n / place) % 10;

        if (before > 0) {
            if (curr == 0) cnt[0] += (before - 1) * place + (after + 1);
            else cnt[0] += before * place;
        }

        for (int d = 1; d <= 9; d++) {
            if (d < curr) cnt[d] += (before + 1) * place;
            else if (d == curr) cnt[d] += before * place + (after + 1);
            else cnt[d] += before * place;
        }

        if (place > n / 10) break;
        place *= 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << ' ';
    }

    return 0;
}