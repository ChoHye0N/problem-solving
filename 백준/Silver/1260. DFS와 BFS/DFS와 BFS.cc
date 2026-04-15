#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;

void dfs(const vector<vector<int>>& graph, vector<int>& visited, int u) {
	visited[u] = 1;
	answer.push_back(u);

	// Visit the lower vertex number first
	vector<int> sortedSub = graph[u];
	sort(sortedSub.begin(), sortedSub.end());

	for (int v : sortedSub)
		if (!visited[v])
			dfs(graph, visited, v);
}

void bfs(const vector<vector<int>>& graph, vector<int>& visited, int u) {
	vector<int> queue;
	int front = 0;

	visited[u] = 1;
	queue.push_back(u);

	while (front < queue.size()) {
		int root = queue[front++];
		answer.push_back(root);

		// Visit the lower vertex number first
		vector<int> sortedSub = graph[root];
		sort(sortedSub.begin(), sortedSub.end());

		for (int sub : sortedSub) {
			if (!visited[sub]) {
				visited[sub] = 1;
				queue.push_back(sub);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int vertexSize, edgeSize, startNode;
	cin >> vertexSize >> edgeSize >> startNode;

	vector<vector<int>> graph(vertexSize + 1);
	vector<int> visited(vertexSize + 1, 0);

	for (int i = 0; i < edgeSize; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(graph, visited, startNode);
	for (int i = 0; i < answer.size() - 1; i++) {
		cout << answer[i] << ' ';
	}
	cout << answer[answer.size() - 1] << '\n';

	answer.clear();
	fill(visited.begin(), visited.end(), 0);

	bfs(graph, visited, startNode);
	for (int i = 0; i < answer.size() - 1; i++) {
		cout << answer[i] << ' ';
	}
	cout << answer[answer.size() - 1] << '\n';

	return 0;
}