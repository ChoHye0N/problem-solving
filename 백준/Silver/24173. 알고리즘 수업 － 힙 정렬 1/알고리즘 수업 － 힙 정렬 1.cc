#include <bits/stdc++.h>
using namespace std;

int cnt = 0, maxN;
vector<int> ans;

void heapify(vector<int> &arr, int k, int n){
    int l = 2 * k, r = 2 * k + 1, s = k;
    
    if (r <= n){
        arr[l] < arr[r] ? s = l : s = r;
    }
    else if (l <= n){
        s = l;
    }
    else return;
    
    if (arr[s] < arr[k]){
        cnt++;
        if (cnt == maxN){
            ans = {min(arr[k], arr[s]), max(arr[k], arr[s])};
        }
        swap(arr[k], arr[s]);
        heapify(arr, s, n);
    }
}

void build_heap(vector<int> &arr, int n){
    for (int i = n / 2; i >= 1; i--){
        heapify(arr, i, n);
    }
}

void heap_sort(vector<int> &arr, int n){
    build_heap(arr, n);
    
    for (int i = n; i > 1; i--){
        cnt++;
        if (cnt == maxN){
            ans = {min(arr[1], arr[i]), max(arr[1], arr[i])};
        }
        swap(arr[1], arr[i]);
        heapify(arr, 1, i - 1);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    maxN = k;
    
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    heap_sort(arr, n);
    
    if (!ans.empty()){
        cout << ans[0] << ' ' << ans[1];
    }
    else{
        cout << -1;
    }
    
    return 0;
}