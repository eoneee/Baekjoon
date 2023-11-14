#include <bits/stdc++.h>
using namespace std;
int n, m;
int num[9];
int seq[9];
int select(int step){
	if(step == m + 1){
		for(int i = 1; i <= m; i++){
			cout << seq[i] << " ";
		}
		cout << "\n";
		return 0;
	}
	for(int i = 1; i <= n; i++){
        seq[step] = i;
        select(step+1);
	}
	return 0;
}
int main() {
	cin >> n >> m;
	select(1);
	return 0;
}