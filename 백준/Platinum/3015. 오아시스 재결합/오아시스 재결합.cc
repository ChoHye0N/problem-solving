#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Person{
    int idx, cnt;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ll res = 0;
    vector<Person> stk;

    for (int i = 0; i < n; i++){
        while (!stk.empty() && arr[stk.back().idx] < arr[i]){
            res += stk.back().cnt;
            stk.pop_back();
        }

        int cnt = 1;

        if (!stk.empty() && arr[stk.back().idx] == arr[i]){
            res += stk.back().cnt;
            cnt = stk.back().cnt + 1;
            stk.pop_back();

            if (!stk.empty()) res++;
        }
        else if (!stk.empty()){
            res++;
        }
        
        stk.push_back({i, cnt});
    }

    cout << res << '\n';

    return 0;
}