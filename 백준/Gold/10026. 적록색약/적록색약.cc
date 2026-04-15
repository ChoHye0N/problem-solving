#include <bits/stdc++.h>
using namespace std;

void bfs(int x, int y, vector<string>& arr, vector<vector<bool>>& visited) {
	queue<pair<int, int>> q;
	char color = arr[x][y];

	q.push({ x, y });
	visited[x][y] = true;

	int dx[4] = { 1, -1, 0, 0 }, dy[4] = {0, 0, 1, -1};

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr.first + dx[i], ny = curr.second + dy[i];

			if (nx >= 0 && nx < arr.size() && ny >= 0 && ny < arr.size() &&
				!visited[nx][ny] && arr[nx][ny] == color) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<string> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j, arr, visited);
				ans1++;
			}
		}
	}

	visited.assign(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}

	int ans2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j, arr, visited);
				ans2++;
			}
		}
	}

	cout << ans1 << ' ' << ans2;

	return 0;
}