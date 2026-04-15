#include <bits/stdc++.h>

using namespace std;

bool check(int n){
    vector<int> arr = { 4, 6, 9, 11 };
    for (int i = 0; i < arr.size(); i++){
        if (n == arr[i]) return true;
    }
    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        int y, m, d = 31;
        cin >> y >> m;
        
        if (m == 1) {
            y--;
            m = 13;
        }
        else if (m == 3){
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) d = 29;
            else d = 28;
        }
        else if (check(m - 1)) d = 30;
        else d = 31;
        
        cout << y << ' ' << (--m) << ' ' << d << '\n';
    }
    
    return 0;
}