#include <iostream>

using namespace std;

int main() {
    int a, b, chicken;
    int ans;
    cin >> a >> b >> chicken;
    ans = (a + b) - 2 * chicken;

    ans >= 0 ? cout << ans << '\n' : cout << a + b << '\n';

    return 0;
}