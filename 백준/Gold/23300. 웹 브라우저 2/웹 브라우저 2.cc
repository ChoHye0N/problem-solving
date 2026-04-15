#include <bits/stdc++.h>
using namespace std;

void compressed(deque<int>& dq) {
    vector<int> res;
    res.push_back(dq[0]);

    for (int i = 1; i < dq.size(); i++) {
        if (dq[i] != dq[i - 1]) {
            res.push_back(dq[i]);
        }
    }

    dq = deque<int>(res.begin(), res.end());

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int curr = -1;
    deque<int> back, front;

    while (q--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'B' && back.size() > 0) {
            front.push_back(curr);
            curr = back.back();
            back.pop_back();
        }
        else if (cmd == 'F' && front.size() > 0) {
            back.push_back(curr);
            curr = front.back();
            front.pop_back();
        }
        else if (cmd == 'A') {
            int p;
            cin >> p;

            front.clear();
            if (curr >= 0) back.push_back(curr);
            curr = p;
        }
        else if (cmd == 'C' && back.size() > 0) {
            compressed(back);
        }
    }

    cout << curr << '\n';
    if (back.size() == 0) {
        cout << -1;
    }
    else {
        for (int i = 0; i < back.size(); i++) {
            cout << back[back.size() - i - 1] << ' ';
        }
    }
    cout << '\n';

    if (front.size() == 0) {
        cout << -1;
    }
    else {
        for (int i = 0; i < front.size(); i++) {
            cout << front[front.size() - i - 1] << ' ';
        }
    }

    return 0;
}