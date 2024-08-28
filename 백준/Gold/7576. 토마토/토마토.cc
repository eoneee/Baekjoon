#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
bool visited[MAX][MAX];
int graph[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int days;
int n, m;
queue<pair<int, int>> tomato;
int bfs(){
	int x, y;
	while(!tomato.empty()){
		int size = tomato.size();
		for(int i = 0; i < size; i++){
			int y = tomato.front().first;
			int x = tomato.front().second;
			tomato.pop();
			for(int j = 0; j < 4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[ny][nx] && graph[ny][nx] == 0){
					visited[ny][nx] = 1;
					tomato.push({ ny, nx });
				}
			}
		}
	
		if(!tomato.empty()){
			days++;
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j] && graph[i][j] == 0){
				cout << -1;
				return 0;
			}
		}
	}
	cout << days;
	return 0;
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 1){
				tomato.push({i, j});
				visited[i][j] = 1;
			}
		}
	}
	bfs();

	return 0;
}