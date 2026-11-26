#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, c;
    cin >> n >> b >> c;

    vector<int> arr(n + 2, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if (b <= c){
        cout << accumulate(arr.begin(), arr.end(), 0LL) * b;
        return 0;
    }

    ll sum = 0;
    for (int i = 0; i < n; i++){
        if (arr[i + 1] > arr[i + 2]){
            ll len2 = min(arr[i], arr[i + 1] - arr[i + 2]);
            sum += len2 * (b + c);
            for (int j = 0; j < 2; j++){
                arr[i + j] -= len2;
            }
        }

        ll len3 = min({arr[i], arr[i + 1], arr[i + 2]});
        sum += len3 * (b + 2 * c);
        for (int j = 0; j < 3; j++){
            arr[i + j] -= len3;
        }

        ll len2 = min(arr[i], arr[i + 1]);
        sum += len2 * (b + c);
        for (int j = 0; j < 2; j++){
            arr[i + j] -= len2;
        }

        sum += 1LL * b * arr[i];
        arr[i] = 0;
    }
    
    cout << sum;

    return 0;
}