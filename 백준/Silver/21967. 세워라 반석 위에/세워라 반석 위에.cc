#include <bits/stdc++.h>
using namespace std;

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
    
    unordered_map<int, int> count;
    unordered_set<int> nums;
    
    int ans = 0, ptr1 = 0, ptr2 = 0;
    
    for (; ptr2 < n; ptr2++){
        int cur = arr[ptr2];
        count[cur]++;
        nums.insert(cur);
        
        while (ptr1 <= ptr2) {
            int maxN = *max_element(nums.begin(), nums.end());
            int minN = *min_element(nums.begin(), nums.end());
            
            if (maxN - minN <= 2) break;
            
            count[arr[ptr1]]--;
            if (count[arr[ptr1]] == 0) {
                nums.erase(arr[ptr1]);
            }
            ptr1++;
        }
        ans = max(ans, ptr2 - ptr1 + 1);
    }
    
    cout << ans;
    
    return 0;
}