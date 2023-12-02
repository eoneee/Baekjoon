#include <bits/stdc++.h>
using namespace std;
int main() {
	int h, w, x, y;	
	cin >> h >> w >> x >> y;
	int a = h + x;
	int b = w + y;
	int arrB[a][b] = {0, };
	int arrA[h][w] = {0, };
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			cin >> arrB[i][j];
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			arrA[i][j] = arrB[i][j];
			if(i >= x && j >= y){
				arrA[i][j] -= arrA[i - x][j - y];
			}
			cout << arrA[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}