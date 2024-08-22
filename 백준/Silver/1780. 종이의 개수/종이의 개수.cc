#include <bits/stdc++.h>
using namespace std;
int mapp[3000][3000];
int ans[2];
int divv[9][4] = {0,0,1,1,
									0,1,1,2,
									0,2,1,3,
									1,0,2,1,
									1,1,2,2,
									1,2,2,3,
									2,0,3,1,
									2,1,3,2,
									2,2,3,3
								 };

int check(int y1, int x1, int y2, int x2) {
	int firstValue = mapp[y1][x1];

	for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
					if (mapp[i][j] != firstValue)
							return 10;
			}
	}

	return firstValue;
}


int pro(int y1, int x1, int y2, int x2){
	int tmp = check(y1, x1, y2, x2);
	if(tmp == -1){
		++ans[0];
		return 0;
	}
	if(tmp == 0){
		++ans[1];
		return 0;
	}
	if(tmp == 1){
		++ans[2];
		return 0;
	}

	tmp = (y2 - y1) / 3;

	for(int i= 0; i< 9; i++){
		pro(y1 + tmp * divv[i][0], x1 + tmp * divv[i][1], y1 + tmp * divv[i][2], x1 + tmp * divv[i][3]);
	}
	return 0;
}


int main() {
	int n; 
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &mapp[i][j]);
		}
	}
	
	pro(1, 1, n + 1, n + 1);
	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);

	
	return 0;
}
