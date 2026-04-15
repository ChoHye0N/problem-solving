#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int score = 0;
    vector<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        if (!stk.empty() && temp == 0) {
            stk.back().second--;
        }
        else if (temp == 1) {
            int rank, times;
            cin >> rank >> times;
            
            stk.push_back({rank, times - 1});
        }
        
        if (!stk.empty() && stk.back().second == 0) {
            score += stk.back().first;
            stk.pop_back();
        }
        
    }
    
    cout << score;
    
    return 0;
}