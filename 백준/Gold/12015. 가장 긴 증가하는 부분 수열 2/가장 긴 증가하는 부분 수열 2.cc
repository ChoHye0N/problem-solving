#include <bits/stdc++.h>

using namespace std;

int b_s(vector<int>& arr, int num) {
    int start = 0, end = arr.size();
    while (start < end) {
        int mid = (start + end) / 2;
        
        if (arr[mid] < num) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int pos = b_s(lis, arr[i]);
        
        if (pos == lis.size()) lis.push_back(arr[i]);
        else lis[pos] = arr[i];
    }
    
    cout << lis.size();
    
    return 0;
}