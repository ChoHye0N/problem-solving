#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int u){
    visited[u] = 1;
    
    for (int v : graph[u]){
        if (!visited[v]){
            dfs(graph, visited, v);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, start;
    cin >> n;
    
    vector<int> a(n);
    vector<vector<int>> graph(n);
    vector<int> visited(n, 0);
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    cin >> start;
    start--;
    
    for (int i = 0; i < n; i++){
        if (i + a[i] < n){
            graph[i].push_back(i + a[i]);
        }
        if (i - a[i] >= 0){
            graph[i].push_back(i - a[i]);
        }
    }
    
    dfs(graph, visited, start);
    
    cout << accumulate(visited.begin(), visited.end(), 0);
    
    return 0;
}