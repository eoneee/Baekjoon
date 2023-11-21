#include <bits/stdc++.h>
using namespace std;

const int maxN = 200;

char arr_temp[maxN][maxN];
int arr[maxN][maxN];
int row, col;

void boom(int i, int j){
	arr[i][j] = -1;
	if(i-1 >= 0)
		arr[i-1][j] = -1;
	if(j-1 >= 0)
		arr[i][j-1] = -1;
	
	if(i+1 < maxN && arr[i+1][j] != 0)
		arr[i+1][j] = -1;
	if(j+1 < maxN && arr[i][j+1] != 0)
		arr[i][j+1] = -1;
	
}


int bomb(int sec){
	//시간 초과
	if(sec == 0){
		for(int i = 0; i < row; ++i){
			for(int j = 0; j < col; ++j){
				if(arr[i][j] != -1){
					cout << 'O';
				}else{
					cout << '.';
				}
			}
			cout << endl;
		}
		return 0;
	}
	//폭탄채우기 //1초후
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			if(arr[i][j] == -1){
				arr[i][j] = 2; //빈칸에 폭탄채우기
			}else
				arr[i][j]--;
		}
	}
	
	sec--; // 1초후
	//시간 초과 
	if(sec == 0){
		for(int i = 0; i < row; ++i){
			for(int j = 0; j < col; ++j){
				if(arr[i][j] != -1){
					cout << 'O';
				}else{
					cout << '.';
				}
			}
			cout << endl;
		}
		return 0;
	}
	//폭탄터뜨리기 // 3초후
	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			if(arr[i][j] == 0){
				boom(i, j);
			}else if(arr[i][j] != -1){
				arr[i][j]--;
			}
		}
	}
	bomb(sec-1);
	return 0;
}
int main() {
	int sec;
	cin >> row >> col >> sec;
	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			cin >> arr_temp[i][j];
			if(arr_temp[i][j] == '.'){
				arr[i][j] = -1; //빈칸
			}else
				arr[i][j] = 1; //폭탄
		}
	}

	//초기상태 1초후
	bomb(sec-1);
	return 0;
}
    