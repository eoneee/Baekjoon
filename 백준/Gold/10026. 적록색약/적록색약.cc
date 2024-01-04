#include <bits/stdc++.h>
using namespace std;
int const MAXX = 102;
char picture[MAXX][MAXX];
int visited[MAXX][MAXX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int area;
int dfs(int y, int x, char color){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(visited[ny][nx] == 0 && picture[ny][nx] == color){
			dfs(ny, nx, picture[ny][nx]);
		}
	}
	return 0;
}
int abdfs(int y, int x, char color){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(color == 'B'){
			if(visited[ny][nx] == 0 && picture[ny][nx] == color){
				abdfs(ny, nx, picture[ny][nx]);
			}
		}else{
			if(visited[ny][nx] == 0 && (picture[ny][nx] == 'G' || picture[ny][nx] == 'R')){
				abdfs(ny, nx, picture[ny][nx]);
			}
		}

	}
	return 0;
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> picture[i + 1][j + 1];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(visited[i][j] == 0){
				dfs(i, j, picture[i][j]);
				area++;
			}
		}
	}
	cout << area << " ";
	memset(visited, 0, sizeof(visited));
	area = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(visited[i][j] == 0){
				abdfs(i, j, picture[i][j]);
				area++;
			}
		}
	}
	cout << area;
	return 0;
}
