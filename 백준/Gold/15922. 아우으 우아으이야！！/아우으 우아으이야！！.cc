#include <bits/stdc++.h>
using namespace std;
int n;
int x, y ;
int startPoint;
int endPoint;
int startTemp;
int endTemp;
int sum;
int overlap(int x, int y){
	if(endPoint >= x){
		if(endPoint < y)
			endPoint = y;
	}else{
		sum += abs(endPoint - startPoint);
		startPoint = x;
		endPoint = y;
		startTemp = 0;
		endTemp = 0;
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		if(i == 0){
			cin >> startPoint >> endPoint;
		}else{
			cin >> startTemp >> endTemp;
		}
		if(i != 0){
			overlap(startTemp, endTemp);
		}
	}
	
	cout << sum + abs(endPoint - startPoint) << endl;
	return 0;
}