#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int ans = 0;
    vector<int> numbers(5);
    for (int i = 0; i < 5; i++)
        cin >> numbers[i];

    for (int i = 0; i < 5; i++)
        ans += pow(numbers[i], 2);

    cout << ans % 10 << '\n';

    return 0;
}