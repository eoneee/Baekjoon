#include<bits/stdc++.h>

using namespace std;
pair<int, int> arr[100001];

int main(){
	int n, start, end;
	int endTime = 0;
	int ans = 1;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> start >> end;
		arr[i] = {end, start};
		
	}
	sort(arr, arr + n);
	endTime = arr[0].first;
	for(int i = 1; i < n; i++){
		if(endTime <= arr[i].second){
			ans++;
			endTime = arr[i].first;
		}
	}
	
	cout << ans << endl;
	return 0;
}