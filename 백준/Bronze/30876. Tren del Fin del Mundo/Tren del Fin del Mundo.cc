#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int minn = 1000;
	int minY = 0;

	vector<pair<int, int>> coordinate(N);
	for(int i = 0; i < N; i++){
		cin >> coordinate[i].first >> coordinate[i].second;
		if(coordinate[i].second < coordinate[minY].second){
			minY = i;
		}
	}
	
		cout << coordinate[minY].first << " " << coordinate[minY].second;
	
	return 0;
}
