#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int plus = 0;
	int rest = 0;
	string plusMark = "++++";
	char restMark = '|';
	int vote[n];
	for(int i = 0; i < n; i++){
		cin >> vote[i];
	}
	for(int i = 0; i < n; i++){
		plus = vote[i] / 5;
		rest = vote[i] % 5;
		for(int j = 0; j < plus; j++){
			cout << plusMark << " ";
		}
		for(int k = 0; k < rest; k++){
			cout << restMark;
		}
	cout << endl;
	}
	return 0;
}