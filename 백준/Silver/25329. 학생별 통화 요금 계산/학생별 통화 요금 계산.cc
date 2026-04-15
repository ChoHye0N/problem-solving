#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> mapp;
    for (int i = 0; i < n; i++) {
        string time, name;
        cin >> time >> name;

        int w = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));

        mapp[name] += w;
    }

    for (auto& p : mapp) {
        int w = p.second;

        if (w <= 100) w = 10;
        else w = ceil(1. * (w - 100) / 50) * 3 + 10;

        p.second = w;
    }

    vector<pair<string, int>> arr(mapp.begin(), mapp.end());
    sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
        });

    for (auto& p : arr) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}