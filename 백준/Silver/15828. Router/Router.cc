#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;
    while (true) {
        int tmp;
        cin >> tmp;

        if (tmp == -1) break;
        else if (tmp == 0) {
            q.pop();
            continue;
        }

        if (q.size() >= n) continue;

        q.push(tmp);
    }

    if (q.empty()) {
        cout << "empty";
        return 0;
    }

    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}