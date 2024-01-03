#include <bits/stdc++.h>
using namespace std;
const int MAXX = 52;
int cabbage[MAXX][MAXX];
int worm;
int visited[MAXX][MAXX];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int dfs(int y, int x){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i ++){
		int ny = y + dy[i];
		int nx = x + dx[i];	
		if(visited[ny][nx] == 0 && cabbage[ny][nx] == 1){
			dfs(ny, nx);
		}
	}
	return 0;
}

int main() {
	int n;
	int a, b, k;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> k;
		for(int j = 0, p = 0, q = 0; j < k; j++){
			cin >> p >> q;
			cabbage[p + 1][q + 1] = 1;
		}
		
		for(int s = 1; s <= a; s++){
			for(int t = 1; t <= b; t++){
				if(cabbage[s][t] == 1 && visited[s][t] == 0){
					dfs(s, t);
					worm++;
					// cout << worm << " " << s << " " << t << endl;
					
				}
			}
		}
		
		cout << worm << endl;
		
		memset(cabbage, 0, sizeof(cabbage));
		memset(visited, 0, sizeof(visited));
		worm = 0;
	}
	return 0;
}