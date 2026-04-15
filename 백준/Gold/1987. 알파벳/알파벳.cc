#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0 ,0}, dy[4] = {0, 0, -1, 1}, ans = 0;
int r, c;

void dfs(vector<string> &arr, vector<bool> &visited, int x, int y, int d){
    ans = max(ans, d);
    
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (!visited[arr[nx][ny] - 'A']){
            visited[arr[nx][ny] - 'A'] = true;
            dfs(arr, visited, nx, ny, d + 1);
            visited[arr[nx][ny] - 'A'] = false;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> c;
    
    vector<string> board(r);
    for (int i = 0; i < r; i++){
        cin >> board[i];
    }
    
    vector<bool> visited(26, false);
    visited[board[0][0] - 'A'] = true;
    
    dfs(board, visited, 0, 0, 1);
    
    cout << ans;
    
    return 0;
}