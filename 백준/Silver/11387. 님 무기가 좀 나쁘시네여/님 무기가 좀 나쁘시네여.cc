#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using llg = long long;

double combat_power(const vector<llg>& stats) {
    llg attack = stats[0];
    llg strength = stats[1];
    llg crit_rate = stats[2];
    llg crit_damage = stats[3];
    llg attack_speed = stats[4];

    double critical_chance = min(crit_rate / 100.0, 1.0);

    double power = attack * (1 + strength / 100.0) *
        ((1 - critical_chance) + critical_chance * crit_damage / 100.0) *
        (1 + attack_speed / 100.0);

    return power;
}

int main() {
    vector<vector<llg>> all_stats(4, vector<llg>(5, 0));

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            cin >> all_stats[i][j];

    double crie_power = combat_power(all_stats[0]);
    double pabu_power = combat_power(all_stats[1]);

    vector<llg> crie_with_pabu_weapon(5);
    for (int i = 0; i < 5; i++) {
        crie_with_pabu_weapon[i] = all_stats[0][i] - all_stats[2][i] + all_stats[3][i];
    }
    double crie_with_pabu_power = combat_power(crie_with_pabu_weapon);

    vector<llg> pabu_with_crie_weapon(5);
    for (int i = 0; i < 5; i++)
        pabu_with_crie_weapon[i] = all_stats[1][i] - all_stats[3][i] + all_stats[2][i];

    double pabu_with_crie_power = combat_power(pabu_with_crie_weapon);

    if (crie_with_pabu_power > crie_power)
        cout << '+' << '\n';
    else if (crie_with_pabu_power < crie_power)
        cout << '-' << '\n';
    else
        cout << '0' << '\n';

    if (pabu_with_crie_power > pabu_power)
        cout << '+' << '\n';
    else if (pabu_with_crie_power < pabu_power)
        cout << '-' << '\n';
    else
        cout << '0' << '\n';

    return 0;
}