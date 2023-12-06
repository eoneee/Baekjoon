#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int dice[1000][4];
	int maxx = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin >> dice[i][j];
		}
		if(dice[i][0] == dice[i][1] && dice[i][1] == dice[i][2] && dice[i][2] == dice[i][0]){
			dice[i][3] = 10000 + dice[i][0] * 1000;
		}else if(dice[i][0] == dice[i][1]){
			dice[i][3] = 1000 + dice[i][0] * 100;
		}else if(dice[i][1] == dice[i][2]){
			dice[i][3] = 1000 + dice[i][1] * 100;
		}else if(dice[i][2] == dice[i][0]){
			dice[i][3] = 1000 + dice[i][2] * 100;
		}else{
			dice[i][3] = max(max(dice[i][0], dice[i][1]), dice[i][2]) * 100;
		}
	}
	for(int i = 0; i < n; i++){
		if(maxx < dice[i][3]){
			maxx = dice[i][3];
		}
	}
	cout << maxx << endl;
	return 0;
}