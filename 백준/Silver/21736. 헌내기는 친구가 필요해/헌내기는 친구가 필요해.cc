#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void bfs(int x, int y, vector<string> &arr, vector<vector<bool>> &visited){
    queue<pair<int, int>> q;
    
    visited[x][y] = true;
    q.push({x, y});
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    while (!q.empty()){
        auto curr = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = curr.first + dx[i], ny = curr.second + dy[i];
            
            if (nx >= 0 && nx < arr.size() && ny >= 0 && ny < arr[0].size() && 
                !visited[nx][ny] && arr[nx][ny] != 'X'){
                if (arr[nx][ny] == 'P') cnt++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;
    
    vector<string> arr(n);
    int x, y;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] == 'I') x = i, y = j;
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    bfs(x, y, arr, visited);
    
    if (cnt == 0) cout << "TT";
    else cout << cnt;
    
    return 0;
}