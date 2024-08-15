#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	int minn = INT_MAX;
	cin >> n >> m;
	vector<vector<int>> enemies(n, vector<int>(3));
	
	for(int i = 0; i < n; i++){
		cin >> enemies[i][0] >> enemies[i][1] >> enemies[i][2];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				int a = enemies[i][0];
				int b = enemies[j][1];
				int c = enemies[k][2];
				
				int cnt = 0;
				
				for(int p = 0; p < n; p++){
					if(a >= enemies[p][0] && b >= enemies[p][1] && c >= enemies[p][2]){
						cnt ++;
					}
				}
				
				if(cnt >= m){
					minn = min(minn, a + b + c);
				}
			}
		}
	}
	
	cout << minn << endl;
	return 0;
}