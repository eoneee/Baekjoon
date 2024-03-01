#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int>> score;
int n;
int solve18(int a){
	int reward;
	if(a > 31){
		reward = 0;
	}else if(a > 15){
		reward = 32;
	}else if(a > 7){
		reward = 64;
	}else if(a > 3){
		reward = 128;
	}else if(a > 1){
		reward = 256;
	}else if(a == 1){
		reward = 512;
	}else{
		reward = 0;
	}
	return reward;
}
int solve17(int a){
	int reward;
	if(a > 21){
		reward = 0;
	}else if(a > 15){
		reward = 10;
	}else if(a > 10){
		reward = 30;
	}else if(a > 6){
		reward = 50;
	}else if(a > 3){
		reward = 200;
	}else if(a > 1){
		reward = 300;
	}else if(a == 1){
		reward = 500;
	}else{
		reward = 0;
	}
	return reward;
}
int main() {
	int sum;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		score.push_back(make_pair(a, b));
		
		sum = (solve17(a) + solve18(b)) * 10000;
		cout << sum;
		cout << endl;
	}

	
	// for(int i = 0; i < n; i++){
	// 	cout << score[i].first << " " << score[i].second << endl;
	// }
	return 0;
}