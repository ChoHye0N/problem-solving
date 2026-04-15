#include <iostream>

using namespace std;

int main() {
    int up, down, goal;
    cin >> up >> down >> goal;

    int status = up - down;

    int days = (goal - down + status - 1) / status;

    cout << days << '\n';

    return 0;
}