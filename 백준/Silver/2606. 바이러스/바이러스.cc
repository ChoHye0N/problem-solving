#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, const vector<vector<int>>& graph, vector<int>& visited) {
	visited[v] = 1;

	for (int u : graph[v])
		if (!visited[u])
			dfs(u, graph, visited);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int vertex_size, edge_size;
	int count = 0;

	cin >> vertex_size;
	cin >> edge_size;

	vector<vector<int>> graph(vertex_size + 1);
	vector<int> visited(vertex_size + 1, 0);

	for (int i = 0; i < edge_size; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, graph, visited);

	for (int i = 0; i < visited.size(); i++)
		count += visited[i];

	cout << count - 1 << '\n';

	return 0;
}