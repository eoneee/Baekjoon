#include <bits/stdc++.h>
using namespace std;
const int MAXX = 102;
bool visited[MAXX][MAXX];
int graph[MAXX][MAXX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt;
int n, m;
queue<pair<int, int>> maze;
int bfs(int y, int x){
	maze.push({y, x});
	visited[y][x] = true;
	
	while(!maze.empty()){
		int y = maze.front().first;
		int x = maze.front().second;
		maze.pop();
		for(int j = 0; j < 4; j++){
			int nx = x + dx[j];
			int ny = y + dy[j];
			if(visited[ny][nx] == false && graph[ny][nx] == 1){
				visited[ny][nx] = true;
				graph[ny][nx] = graph[y][x] + 1;
				maze.push({ny, nx});
			}
		}
	}
	return 0;
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d", &graph[i][j]);
		}
	}
	bfs(1, 1);
	cout << graph[n][m];
	return 0;
}