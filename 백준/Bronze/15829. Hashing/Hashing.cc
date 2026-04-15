#include <iostream>
#include <string>
#include <cmath>

#define R 31
#define M 1234567891

using namespace std;

int main() {
    int len;
    cin >> len;

    string num;
    cin >> num;

    long long sum = 0;
    long long power = 1;
    for (int i = 0; i < len; i++) {
        sum = (sum + (num[i] - 'a' + 1) * power) % M;
        power = (power * R) % M;
    }

    cout << sum << '\n';

    return 0;
}