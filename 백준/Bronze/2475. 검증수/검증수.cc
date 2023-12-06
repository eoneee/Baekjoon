#include <bits/stdc++.h>
using namespace std;
int main() {
	int a;
	int number[5] = {0, };
	int sum = 0;
	for(int i = 0; i < 5; i++){
		cin >> a;
		number[i] = pow(a,2);
		sum += number[i];
	}
	cout << sum % 10 << endl;
	return 0;
}