#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> domjudge;
    map<string, int> kattis;

    for (int i = 0; i < n; ++i) {
        string result;
        cin >> result;
        domjudge[result]++;
    }

    for (int i = 0; i < n; ++i) {
        string result;
        cin >> result;
        kattis[result]++;
    }

    int max_matches = 0;

    for (const auto& entry : domjudge) {
        const string& result = entry.first;
        int domjudge_count = entry.second;

        if (kattis.find(result) != kattis.end()) {
            int kattis_count = kattis[result];
            max_matches += min(domjudge_count, kattis_count);
        }
    }

    cout << max_matches << '\n';

    return 0;
}