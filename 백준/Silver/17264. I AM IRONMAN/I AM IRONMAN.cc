#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n, playerNum, win, lose, g, score = 0;
    cin >> n >> playerNum >> win >> lose >> g;

    map<string, char> player;
    for (int i = 0; i < playerNum; i++) {
        string name;
        char flag;
        cin >> name >> flag;
        player[name] = flag;
    }

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if (player.find(name) != player.end()) {
            if (player[name] == 'W') {
                score += win;
            }
            else if (player[name] == 'L') {
                score -= lose;
                if (score < 0) score = 0;
            }
        }
        else {
            score -= lose;
            if (score < 0) score = 0;
        }

        if (score >= g) break;
    }

    score >= g ? cout << "I AM NOT IRONMAN!!" << '\n' : cout << "I AM IRONMAN!!" << '\n';

    return 0;
}