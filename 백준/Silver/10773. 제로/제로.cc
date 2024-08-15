#include<bits/stdc++.h>

using namespace std;

int main(){
	int k;
	cin >> k;
	int num;
	vector<int>arr(k);
	int ans = 0;
	for(int i = 0; i < k; i++){
		cin >> num;
		if(num == 0){
			arr.pop_back();
		}else{
			arr.push_back(num);
		}
	}
	for(int i = 0; i < arr.size(); i++){
		ans += arr[i];
	}

	cout << ans << endl;
	return 0;
}