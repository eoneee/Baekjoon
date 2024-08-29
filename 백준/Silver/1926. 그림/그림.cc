#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char graph[500][500];
int dir[4][2] = { 0,1,
								 1,0,
								 0,-1,
								 -1,0 };
int maxWidth;
int visited[500][500];
int width;

void dfs(int y, int x) {
	visited[y][x] = true;
	width++;

	for (int i = 0; i < 4; i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (visited[ny][nx]) continue;
		if (ny >= 0 && ny < n && nx >= 0 && nx < m && graph[ny][nx]=='1') {
			dfs(ny, nx);
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && graph[i][j] == '1') {
				cnt++;
				width = 0;
				dfs(i,j);
				maxWidth = max(maxWidth, width);
			}
		}
	}
	cout << cnt << '\n' << maxWidth;
	return 0;
}