#include <bits/stdc++.h>
using namespace std;
int n;

int cantor(int num){
	int size = pow(3, num -1);
	if(num == 0){
		cout << '-';
		return 0;
	}

	cantor(num - 1);
	for(int i = 0; i < size; i++){
		cout << ' ';
	}
	cantor(num - 1);
	return 0;
}
int main() {
	while(cin >> n){
		cantor(n);
		cout << endl;
	}

	return 0;
}