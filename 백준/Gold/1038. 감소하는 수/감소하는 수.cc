#include <bits/stdc++.h>

using namespace std;
using llg = long long;

vector<llg> nums;

void dfs(llg num, int last) {
    nums.push_back(num);
    
    for (int i = 0; i < last; i++) {
        dfs(num * 10 + i, i);
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < 10; i++) {
        dfs(i, i);
    }
    sort(nums.begin(), nums.end());
    
    cout << (n >= nums.size() ? -1 : nums[n]);

    return 0;
}