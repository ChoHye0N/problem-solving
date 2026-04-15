#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void bfs(int x, int y, vector<string> &arr, vector<vector<bool>> &visited){
    queue<pair<int, int>> q;
    
    q.push({x, y});
    visited[x][y] = true;
    
    int sum = 1, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    while (!q.empty()){
        auto curr = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = curr.first + dx[i], ny = curr.second + dy[i];
            
            if (nx >= 0 && nx < arr.size() && ny >= 0 && ny < arr.size() && 
                !visited[nx][ny] && arr[nx][ny] == '1'){
                sum++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    ans.push_back(sum);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> arr(n);
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == '1' && !visited[i][j]){
                bfs(i, j, arr, visited);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}