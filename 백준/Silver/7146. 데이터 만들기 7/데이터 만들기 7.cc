#include <iostream>
#include <vector>

#define MAX_V 71
#define MAX_E 1501

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> edges;

    cout << MAX_V << " " << MAX_E << '\n';

    for (int i = 0; i < MAX_V && edges.size() < MAX_E; i++) {
        for (int j = i + 1; j < MAX_V && edges.size() < MAX_E; j++) {
            edges.push_back(make_pair(i, j));
        }
    }

    for (const auto& edge : edges)
        cout << edge.first << " " << edge.second << '\n';

    return 0;
}