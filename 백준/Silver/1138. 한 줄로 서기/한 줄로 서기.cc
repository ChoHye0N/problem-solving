#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> res(n, INT_MAX);
    for (int i = 0; i < n; i++){
        int curr, cnt = 0;
        cin >> curr;

        for (int pos = 0; pos < n; pos++){
            if (res[pos] == INT_MAX){
                if (cnt == curr){
                    res[pos] = i + 1;
                    break;
                }
                cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << res[i] << ' ';
    }

    return 0;
}