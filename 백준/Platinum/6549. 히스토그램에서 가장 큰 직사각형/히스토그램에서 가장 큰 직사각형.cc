#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true){
        int n;
        cin >> n;

        if (n == 0) break;

        vector<int> arr(n + 1);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        arr[n] = 0;

        ll res = 0;
        vector<int> stk;
        for (int i = 0; i <= n; i++){
            while (!stk.empty() && arr[stk.back()] > arr[i]){
                int h = arr[stk.back()];
                stk.pop_back();

                int w = (stk.empty() ? i : i - stk.back() - 1);

                res = max(res, 1LL * h * w);
            }
            stk.push_back(i);
        }

        cout << res << '\n';
    }

    return 0;
}