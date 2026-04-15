#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        int total, conservativeParty, reformistParty;
        cin >> total >> conservativeParty >> reformistParty;

        if (total == 0 && conservativeParty == 0 && reformistParty == 0)
            break;

        int independentParty = total - (conservativeParty + reformistParty);
        int majority = (total / 2) + 1;

        if (conservativeParty >= majority) {
            cout << 0 << '\n';
        }
        else if (conservativeParty + independentParty < majority) {
            cout << -1 << '\n';
        }
        else {
            cout << majority - conservativeParty << '\n';
        }
    }

    return 0;
}