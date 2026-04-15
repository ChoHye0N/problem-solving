#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int quarter = 0, half = 0, threeQuarter = 0;

    for (int i = 0; i < n; i++) {
        string size;
        cin >> size;

        if (size == "1/4")
            quarter++;
        else if (size == "3/4")
            threeQuarter++;
        else if (size == "1/2")
            half++;
    }

    int pizza = threeQuarter;
    quarter = max(0, quarter - threeQuarter);

    pizza += half / 2;
    half %= 2;

    if (half > 0) {
        pizza++;
        quarter = max(0, quarter - 2);
    }

    pizza += quarter / 4;
    if (quarter % 4 > 0) pizza++;

    cout << pizza << '\n';

    return 0;
}