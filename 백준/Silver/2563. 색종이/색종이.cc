#include <bits/stdc++.h>
using namespace std;
int color[101][101];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		for(int a = x; a <= x + 9; a++){
			for(int b = y; b <= y + 9; b++){
				color[a][b] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			ans += color[i][j];
		}
	}
	
	cout << ans;
	return 0;
}