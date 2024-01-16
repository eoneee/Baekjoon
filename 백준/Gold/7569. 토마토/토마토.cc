#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
int visited[MAX][MAX][MAX];
int graph[MAX][MAX][MAX];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int days;
int n, m, h;
queue<tuple<int, int, int>> tomato; //좌표입력
int bfs(){
	int days = 0;
	int x, y, z;
	while(!tomato.empty()){
		int size = tomato.size();
		for(int i = 0; i < size; i++){
			int z = get<0> (tomato.front());
			int y = get<1> (tomato.front());
			int x = get<2> (tomato.front());
			tomato.pop();
			for(int j = 0; j < 6; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				int nz = z + dz[j];
				if(nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h && visited[nz][ny][nx] == 0 && graph[nz][ny][nx] == 0){
					visited[nz][ny][nx] = 1;
					tomato.push({ nz, ny, nx });
				}
			}
		}
		if(!tomato.empty()){
			days++;
		}
	}
	
	for(int q = 0; q < h; q++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(visited[q][i][j] == 0 && graph[q][i][j] == 0){
					cout << -1;
					return -1;
				}
			}
		}
	}
	cout << days;
	return days;
}
int main() {
	cin >> n >> m >> h;
	while (!tomato.empty()) {
			tomato.pop();  // 각 테스트 케이스마다 큐 비워주기
	}
	for(int q = 0; q < h; q++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
					cin >> graph[q][i][j];
					if(graph[q][i][j] == 1){
						tomato.push({q, i, j});
						visited[q][i][j] = 1;
					}else if(graph[q][i][j] == -1){
						visited[q][i][j] = -1;
					}
				}
			}
		}
	
	bfs();

	return 0;
}