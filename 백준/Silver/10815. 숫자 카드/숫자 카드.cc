#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cin >> m;
    vector<int> brr(m);
    for (int i = 0; i < m; i++){
        cin >> brr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < m; i++){
        int start = 0, end = n - 1;
        bool flag = false;
        
        while (start <= end){
            int mid = start + (end - start) / 2;
            
            if (brr[i] > arr[mid]) start = mid + 1;
            else if (brr[i] < arr[mid]) end = mid - 1;
            else {
                flag = true;
                break;
            }
        }
        if (flag) cout << "1 ";
        else cout << "0 ";
    }
    
    return 0;
}