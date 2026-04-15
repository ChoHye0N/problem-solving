#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, d, k, count = 0;
    cin >> n >> d >> k;
    
    vector<int> stars(n), ans(n, 0);
    for (int i = 0; i < n; i++){
        cin >> stars[i];
    }
    
    for (int i = 0; i < d; i++){
        bool cleaning = false;
        for (int j = 0; j < n; j++){
            if (ans[j] + stars[j] > k) {
                cleaning = true;
                break;
            }
        }
        if (cleaning) {
            fill(ans.begin(), ans.end(), 0);
            count++;
        }
        for (int j = 0; j < n; j++){
            ans[j] += stars[j];
        }
    }
    
    cout << count;
    
    return 0;
}