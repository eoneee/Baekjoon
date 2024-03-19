#include <bits/stdc++.h>
using namespace std;
const int M = 500;
const int N = 500;
int mapp[M][N];
int a, b;
int sum;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int mem[M][N];
int temp = 0;
int cnt;

int dp(int y, int x){
	
	if(y == a - 1 && x == b - 1){
		return 1;
	}
	
	if(mem[y][x] != -1){
		return mem[y][x];
	}
	
	mem[y][x] = 0;
	// 현재 상태까지의 경우의 수를 다 구했는가?
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx >= 0 && ny >= 0 && ny < a && nx < b && mapp[ny][nx] < mapp[y][x]){
			mem[y][x] += dp(ny, nx);
		}
	}
	return mem[y][x];
}

int main() {
	
	memset(mem, -1, sizeof(mem));
	
	cin >> a >> b;
	
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cin >> mapp[i][j];
		}
	}

	// dp(0, 0);
	cout << dp(0, 0);

	
	
	return 0;
}