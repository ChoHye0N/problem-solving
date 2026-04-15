#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        int n, m, count = 0;
        cin >> n >> m;

        if (!n && !m) break;

        vector<int> customerKey(n, 0);

        for (int i = 0; i < n; i++)
            cin >> customerKey[i];

        for (int i = 0; i < m; i++) {
            int flag = 1;

            for (int j = 0; j < n; j++) {
                int cuts;
                cin >> cuts;

                if (cuts > customerKey[j]) flag = 0;
            }
            if (flag) count++;
        }
        cout << count << '\n';
    }

    return 0;
}