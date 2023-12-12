#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int box[N][N];
	int k = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> box[i][j];
			box[i][j] = k;
		}
		k++;
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << box[i][j] <<" ";
		}
		cout << endl;
	}
	
	return 0;
}
