#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string board;
    cin >> board;
    
    string ans = "";
    int count = 0;

    for (int i = 0; i <= board.size(); i++) {
        if (i < board.size() && board[i] == 'X') {
            count++;
        }
        else {
            if (count % 2 != 0) {
                cout << -1;
                return 0;
            }
            while (count >= 4) {
                ans += "AAAA";
                count -= 4;
            }
            while (count >= 2) {
                ans += "BB";
                count -= 2;
            }
            if (i < board.size()) {
                ans += board[i];
            }
        }
    }
    
    cout << ans;
    
    return 0;
}