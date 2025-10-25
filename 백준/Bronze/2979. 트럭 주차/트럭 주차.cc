#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int times[100];
int ans;
//vector<int> sortTime;
int temp1, temp2;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(times, times + 100, 0);
	cin >> n >> m >> k;
	
	for(int i = 0; i < 3; i++){
		cin >> temp1 >> temp2;
		//sortTimes.push_back(temp);
		for(int j = temp1; j < temp2; j++){
			times[j]++;
		}
	}
	//sort.sortTime();
	for(int i = 0; i < 100; i++){
		if(times[i] == 3){
			ans += 3 * k;
		}else if(times[i] == 2){
			ans += 2 * m;
		}else if(times[i] == 1){
			ans += 1 * n;
		}
	}
	cout << ans;
	return 0;
}