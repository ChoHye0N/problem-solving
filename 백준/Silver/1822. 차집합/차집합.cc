#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    
    int temp;
    set<int> arr, brr, ans;
    for (int i = 0; i < a; i++){
        cin >> temp;
        arr.insert(temp);
    }
    for (int i = 0; i < b; i++){
        cin >> temp;
        brr.insert(temp);
    }
    
    auto ptr1 = arr.begin(), ptr2 = brr.begin();
    
    while (ptr1 != arr.end() && ptr2 != brr.end()) {
        if (*ptr1 < *ptr2) {
            ans.insert(*ptr1);
            ptr1++;
        }
        else if (*ptr2 < *ptr1) {
            ptr2++;
        }
        else {
            ptr1++;
            ptr2++;
        }
    }
    
    while (ptr1 != arr.end()) {
        ans.insert(*ptr1);
        ptr1++;
    }
    
    cout << ans.size() << '\n';
    for (int x : ans) {
        std::cout << x << ' ';
    }
    
    return 0;
}