#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int visited[MAX][MAX][2];
int graph[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
queue<tuple<int, int, int>> mapp; //좌표입력
int bfs(){
	
	while(!mapp.empty()){
		
		int x, y, z;
		tie(x, y, z) = mapp.front();
		mapp.pop();

		for(int j = 0; j < 4; j++){
			int nx = x + dx[j];
			int ny = y + dy[j];
			if(nx >= 0 && ny >= 0 && nx < n && ny < m){
				// is wall
				if(graph[nx][ny] == 1){
					if(z == 0){ // can through
						visited[nx][ny][1] = visited[nx][ny][1] == 0 ? visited[x][y][0] + 1 : 0;
						mapp.push({nx, ny, 1});
					}
				}
				// is space
				else{
					if(visited[nx][ny][z] == 0){
						visited[nx][ny][z] = visited[x][y][z] + 1;
						mapp.push({nx, ny, z});
					}
				}
			}
		}
	}
	
	return 0;
}
int main() {
	cin >> n >> m;
	int a;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a);
			graph[i][j] = a;
		}
	}
	mapp.push({0,0,0});
	bfs();
	
	// if(graph[n-1][m-1] == 0)
	// 	cout << -1 << endl;
	// else
	// 	cout << graph[n-1][m-1] << endl;
	int result;
	n--;
	m--;
	
	if(min(visited[n][m][0], visited[n][m][1]) != 0)
		result = min(visited[n][m][0], visited[n][m][1]);
	else
		result = max(visited[n][m][0], visited[n][m][1]);
	
	if(result == 0) 
		result = -2;
		
	if(n == 0 && m == 0)
	    result = 0;
	cout << result + 1 << endl;
	
	return 0;
}