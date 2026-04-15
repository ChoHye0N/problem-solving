#include <bits/stdc++.h>
using namespace std;

auto cmp = [](int a, int b) {
    if (abs(a) == abs(b)) return a > b;
    return abs(a) > abs(b);
    };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(tmp);
    }

    return 0;
}