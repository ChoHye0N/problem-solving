#include <bits/stdc++.h>
using namespace std;
using llg = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<llg> arr(n);
    llg sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    bool flag = false;

    if (sum % 2 != 0) {
        flag = true;
    }
    
    else {
        llg curr = 0;
        
        for (int i = 0; i < n - 1; i++) {
            curr += arr[i];
            
            if (curr % 2 == 0) {
                flag = true;
                break;
            }
        }
    }

    cout << (flag ? 1 : 0);

    return 0;
}