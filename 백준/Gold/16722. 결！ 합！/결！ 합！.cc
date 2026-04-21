#include <bits/stdc++.h>
using namespace std;

vector<int> stk;
map<set<int>, bool> checked;

struct Card {
    string s, c, b;
};

bool is_ok(Card a, Card b, Card c) {
    auto cmp = [](string x, string y, string z) {
        return (x == y && y == z) || (x != y && y != z && x != z);
        };

    return cmp(a.s, b.s, c.s) && cmp(a.c, b.c, c.c) && cmp(a.b, b.b, c.b);
}

void dfs(vector<Card>& arr, int d) {
    if (stk.size() == 3) {
        Card a = arr[stk[0]], b = arr[stk[1]], c = arr[stk[2]];

        if (is_ok(a, b, c)) {
            checked[{ stk[0], stk[1], stk[2] }] = true;
        }

        return;
    }

    for (int i = d; i < 9; i++) {
        stk.push_back(i);
        dfs(arr, i + 1);
        stk.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Card> arr(9);
    for (int i = 0; i < 9; i++) {
        cin >> arr[i].s >> arr[i].c >> arr[i].b;
    }

    int t;
    cin >> t;

    dfs(arr, 0);

    int ans = 0;
    bool gCheck = false;

    while (t--) {
        char op;
        cin >> op;

        if (op == 'H') {
            set<int> cards;

            for (int i = 0; i < 3; i++) {
                int tmp;
                cin >> tmp;

                cards.insert(tmp - 1);
            }

            if (checked[cards]) {
                ans++;
                checked[cards] = false;
            }
            else if (!checked[cards]) {
                ans--;
            }
        }
        else if (op == 'G') {
            bool ok = true;

            for (auto& [k, v] : checked) {
                if (v == true) ok = false;
            }

            if (ok && !gCheck) {
                ans += 3;
                gCheck = true;
            }
            else ans--;
        }
    }

    cout << ans;

    return 0;
}