#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), [](string& a, string& b){
        return a + b > b + a;
    });

    if (arr.empty() || arr[0] == "0") {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++){
        cout << arr[i];
    }

    return 0;
}