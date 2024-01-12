#include <bits/stdc++.h>
using namespace std;
int N;
int len;
const int MAXX = 302;
bool visited[MAXX][MAXX];
int chess[MAXX][MAXX];
int targetX, targetY;
queue<pair<int, int>> knight;
int bfs(int starty, int startx){
	int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	if (startx == targetX && starty == targetY)
		return chess[starty][startx];
	knight.push({starty, startx});
	chess[starty][startx] = 0;
	visited[starty][startx] = true;

	while(!knight.empty()){
		int y = knight.front().first;
		int x = knight.front().second;
		knight.pop();
		
		for(int i = 0; i < 8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx < len && ny < len && visited[ny][nx] == 0){
				chess[ny][nx] = chess[y][x] + 1;
				visited[ny][nx] = true;
				knight.push({ny, nx});
				if (nx == targetX && ny == targetY) {
					return chess[ny][nx];
				}
			}
			
		}
	}
	return -1;
}

int main() {
	cin >> N;
	int a, b;
	for(int i = 0 ; i < N; i++){
		cin >> len >> a >> b >> targetY >> targetX;
		memset(visited, 0, sizeof(visited));
		memset(chess,0, sizeof(chess));
		while(!knight.empty())
			knight.pop();
		bfs(a, b);
		cout << chess[targetY][targetX] << endl;
	}
	return 0;
}

