#include <bits/stdc++.h>
using namespace std;

int board[101], visited[101];

void bfs() {
	fill(visited, visited + 101, -1);
	queue<int> q;

	q.push(1);
	visited[1] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nx = curr + i;

			if (nx > 100) continue;

			if (board[nx] != 0) nx = board[nx];

			if (visited[nx] == -1) {
				visited[nx] = visited[curr] + 1;
				q.push(nx);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n + m; i++) {
		int a, b;
		cin >> a >> b;

		board[a] = b;
	}

	bfs();

	cout << visited[100];

	return 0;
}