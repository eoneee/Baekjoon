#include <bits/stdc++.h>
using namespace std;
pair<int, int> ground[12];

int main() {
	int n;
	int dir, len;
	int bigArea = 0;
	int smallArea = 0;
	cin >> n;
	
	for(int i = 0; i < 6; i++){
		cin >> dir >> len;
		ground[i] = ground[i + 6] = {dir, len};
	}
	
	for(int i = 3; i < 10; i++){
		if(ground[i].first == ground[i - 2].first && ground[i - 1].first == ground[i - 3].first){
			bigArea = ground[i + 1].second * ground[i + 2].second;
			smallArea = ground[i - 1].second * ground[i - 2].second;
			break;
		}
	}
	
	cout << n * (bigArea - smallArea) << endl;
	
	return 0;
}
