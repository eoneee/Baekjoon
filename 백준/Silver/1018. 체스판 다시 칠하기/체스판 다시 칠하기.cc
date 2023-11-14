#include <bits/stdc++.h>
using namespace std;
int x, y;
char chessWord[50][50];
bool chess[50][50];
int cnt_b;
int cnt_w;
bool blackBox[8][8];
bool whiteBox[8][8];
int a, b;
int minn = 64;
int check(int startX, int startY){
	
	a = 0;
	b = 0;
	cnt_b = 0;
	cnt_w = 0;
	for(int i = startX; i < startX + 8; i++){
		b = 0;
		for(int j = startY; j < startY + 8; j++){
			if(blackBox[a][b] != chess[i][j]){
				cnt_b++;
			}
			if(whiteBox[a][b] != chess[i][j]){
				cnt_w++;
				
			}
			b++;
		}
		a++;
	}
	minn = min(minn, min(cnt_b, cnt_w));
	return 0;
}
int main() {
	cin >> x >> y;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cin >> chessWord[i][j];
			if(chessWord[i][j] == 'B'){
				chess[i][j] = 1;
			}if(chessWord[i][j] == 'W'){
				chess[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(i % 2 == 0){
				if(j % 2 == 0){
					blackBox[i][j] = 1;
					whiteBox[i][j] = 0;
				}else{
					blackBox[i][j] = 0;
					whiteBox[i][j] = 1;	
				}
			}else{
				if(j % 2 == 0){
					blackBox[i][j] = 0;
					whiteBox[i][j] = 1;
				}else{
					blackBox[i][j] = 1;
					whiteBox[i][j] = 0;	
				}
			}
		}
	}
	// for(int i = 0; i < 8; i++){
	// 	for(int j = 0; j < 8; j++){
	// 		cout << blackBox[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "==========" << endl;
	// for(int i = 0; i < 8; i++){
	// 	for(int j = 0; j < 8; j++){
	// 		cout << whiteBox[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for(int i = 0; i <= x-8; i++){
	 	for(int j = 0; j <= y-8; j++){
	 		check(i,j);
	 	}
    }
    cout << minn << endl;
    
	return 0;
}