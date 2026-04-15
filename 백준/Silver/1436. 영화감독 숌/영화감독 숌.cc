#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0, num = 666;

    while (true) {
        if (to_string(num).find("666") != -1) count++;
        if (count == n) break;
        num++;
    }

    cout << num << '\n';

    return 0;
}