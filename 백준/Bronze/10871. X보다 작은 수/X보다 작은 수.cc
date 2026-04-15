#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n, 0);
    vector<int> ans;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    for(int i = 0; i < n; i++)
        if (arr[i] < x)
            ans.push_back(arr[i]);
    
    for(int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ' ';
    cout << ans[ans.size() - 1] << '\n';
}