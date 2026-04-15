#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> b(n);
    unordered_set<int> types;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        types.insert(b[i]);
    }

    int result = 0;

    for (int delVal : types) {
        int maxLen = 0, curLen = 0, prev = -1;

        for (int i = 0; i < n; i++) {
            if (b[i] == delVal) continue;

            if (b[i] == prev) curLen++;
            else {
                curLen = 1;
                prev = b[i];
            }

            maxLen = max(maxLen, curLen);
        }

        result = max(result, maxLen);
    }

    cout << result;
    return 0;
}