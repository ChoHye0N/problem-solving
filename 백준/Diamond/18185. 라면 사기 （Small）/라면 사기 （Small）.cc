#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n + 2, 0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++){
        // 미리 2칸 처리
        if (arr[i + 1] > arr[i + 2]){
            int len2 = min(arr[i], arr[i + 1] - arr[i + 2]);
            sum += len2 * 5;
            for (int j = 0; j < 2; j++){
                arr[i + j] -= len2;
            }
        }

        // 3칸 처리
        int len3 = min({arr[i], arr[i + 1], arr[i + 2]});
        sum += len3 * 7;
        for (int j = 0; j < 3; j++){
            arr[i + j] -= len3;
        }
        
        // 2칸 처리
        int len2 = min(arr[i], arr[i + 1]);
        sum += len2 * 5;
        for (int j = 0; j < 2; j++){
            arr[i + j] -= len2;
        }

        // 1칸 처리
        sum += arr[i] * 3;
        arr[i] = 0;
    }
    
    cout << sum;

    return 0;
}