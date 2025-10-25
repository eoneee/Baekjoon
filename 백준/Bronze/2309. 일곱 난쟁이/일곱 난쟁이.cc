#include<bits/stdc++.h>
using namespace std;
vector<int> vec(9);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sum = 0;

	for(int i = 0; i < 9; i ++){
		cin >> vec[i];
		sum += vec[i];
	}
	int out1 = -1;
	int out2 = -1;

	for(int i = 0; i < 9; i++){
		for(int j = i + 1; j < 9; j++){
			if(sum - (vec[i] + vec[j]) == 100){
				out1 = i;
				out2 = j;
				break;
			}
		}
		//if(out1 != -1) break;
	}
	vector<int> ans;
	for(int i = 0 ; i < 9 ; i++){
		if(i == out1 || i == out2) continue;
		ans.push_back(vec[i]);
	}

	sort(ans.begin(), ans.end());
	for(int x : ans) cout << x << "\n";
}