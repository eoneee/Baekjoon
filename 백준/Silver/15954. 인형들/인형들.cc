#include <bits/stdc++.h>
using namespace std;

int tlqnfxod[500];
double solve(int a, int b){ // [a, b]
	
	int range = (b - a + 1);
	
	double sum = 0;
	double avg;
	double temp = 0;
	
	for(int j = a; j <= b; j++){
		sum += tlqnfxod[j];
	}
	avg = sum / range;
	
	for(int k = a; k <= b; k++){
		temp += pow(tlqnfxod[k] - avg, 2);
	}
	double var = temp / range;

	return sqrt(var);
}

int main() {
	int N, K;
	cin >> N >> K;
	double minn = 1e9;
	for(int i = 0; i < N; i++){
		cin >> tlqnfxod[i];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(j >= i && j - i + 1 >= K){
				minn = min(minn, solve(i, j));
			}
		}
	}
	
	cout.precision(8);
	cout << minn;
	return 0;
}