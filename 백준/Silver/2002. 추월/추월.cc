#include <bits/stdc++.h>
using namespace std;
int n;
string carIn[1000];
string carOut[1000];
int cnt;


int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> carIn[i];
	}
	for(int i = 0; i < n; i++){
		cin >> carOut[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(carIn[i] == carOut[j]){
				
				for(int k = 0; k < i; k++){
					int flag = 0;
					for(int a = 0; a < j; a++){
						if(carIn[k] == carOut[a]){
							flag = 1;
							break;
						}
					}
					if(flag == 0){ // 먼저 들어간차가 아직 안나옴
						cnt++;
						break;
					}
				}
			}
		}
	}

	cout << cnt << endl;
	return 0;
}