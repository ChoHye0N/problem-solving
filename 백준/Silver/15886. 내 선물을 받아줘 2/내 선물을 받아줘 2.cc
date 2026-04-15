#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find_cycle(vector<int>& visited, int visit_idx, int pos, const string& move) {
    int start = pos;

    while (1) {
        visited[pos] = visit_idx;
        int next = (move[pos] == 'E') ? pos + 1 : pos - 1;

        if (visited[next] == visit_idx)
            return 1;
        if (visited[next] != 0)
            return 0;

        pos = next;
    }
}

int main() {
    int n;
    string move;
    cin >> n >> move;

    vector<int> visited(n, 0);
    int cycle = 0;

    for (int i = 0; i < n; i++)
        if (visited[i] == 0)
            cycle += find_cycle(visited, i + 1, i, move);

    cout << cycle << '\n';
    return 0;
}