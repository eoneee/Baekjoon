#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int visited[N + 1][N + 1] = {0, };
int mapp[N + 1][N + 1];
int n;

int dfs(int y, int x, int w){
	visited[y][x] = 1;
	int dy[4] = {0, 0, 1, -1}; //동서남북
	int dx[4] = {1, -1, 0, 0};
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i]; // 남북 중 하나
		int nx = x + dx[i]; // 동서 중 하나
		if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //배열크기 넘어갔을 경우 
		if(visited[ny][nx] || mapp[ny][nx] <= w) continue; // 방문하지 않았고, 강수량보다 낮은 경우
		dfs(ny, nx, w); // 다음 인접 지역 확인
	}
	return 0;
}


int main() {
	int ans = 1;
	cin >> n;
	int maxx = 1;
	for(int y = 0; y < n; y++){
		for(int x = 0; x < n; x++){
			cin >> mapp[y][x];
			if(mapp[y][x] > maxx)
				maxx = mapp[y][x];
		}
	}
	
	for(int w = 1; w < maxx; w++){
		int chk = 0;
		memset(visited, 0, sizeof(visited));
		for(int y = 0; y < n; y++){
			for(int x = 0; x < n; x++){
				if(mapp[y][x] > w && !visited[y][x]){
					chk++;
					dfs(y, x, w);
				}else{
					visited[y][x] = 1;
				}
			}
		}
		
		if(chk > ans)
			ans = chk;
	}
	
	cout << ans << endl;
	return 0;
}