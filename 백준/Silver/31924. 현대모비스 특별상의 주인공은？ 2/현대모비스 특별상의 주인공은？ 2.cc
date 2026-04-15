#include <bits/stdc++.h>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> board(n);
    for (int i = 0; i < n; i++){
        cin >> board[i];
    }
    
    string target1 = "MOBIS", target2 = "SIBOM";
    int dx[4] = {1, 0, 1, 1}, dy[4] = {0, 1, 1, -1}, cnt = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int dir = 0; dir < 4; dir++){
                string word = "";
                bool isValid = true;
                
                for (int k = 0; k < 5; k++){
                    int x = i + dx[dir] * k;
                    int y = j + dy[dir] * k;
                    
                    if (x < 0 || x >= n || y < 0 || y >= n){
                        isValid = false;
                        break;
                    }
                    
                    word += board[x][y];
                }
                
                if (isValid && (target1 == word || target2 == word)){
                    cnt++;
                }
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}