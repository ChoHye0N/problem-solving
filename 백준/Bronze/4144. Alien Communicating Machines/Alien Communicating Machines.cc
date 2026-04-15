#include <iostream>
#include <string>
#include <algorithm>

using llg = long long;
using namespace std;
string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string to_base(llg value, int base) {
    if (value == 0) return "0";

    string result = "";

    while (value > 0) {
        result += digits[value % base];
        value /= base;
    }

    reverse(result.begin(), result.end());
    return result;
}

llg to_decimal(const string& z, int baseX) {
    llg result = 0;
    llg power = 1;

    for (int i = z.size() - 1; i >= 0; i--) {
        char c = z[i];
        int value = (isdigit(c)) ? c - '0' : c - 'A' + 10;
        result += value * power;
        power *= baseX;
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int baseX, baseY;
        string z;
        cin >> baseX >> baseY >> z;

        llg decimal_value = to_decimal(z, baseX);

        string result = to_base(decimal_value, baseY);
        cout << result << endl;
    }

    return 0;
}