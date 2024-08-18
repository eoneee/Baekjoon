#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int maxx = 0;
	int weight;
	cin >> n;
	
	
	vector<int> rope(n);
	
	for(int i = 0; i < n; i++){
		cin >> rope[i];
	}
	
	sort(rope.begin(), rope.end());
	
	
	for(int i = 0; i < n; i++){
		weight = rope[i] * (n - i);
		// cout << weight;
		maxx = max(maxx, weight);
	}
	
	cout << maxx << endl;
	return 0;
}