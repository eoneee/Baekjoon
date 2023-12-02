#include <bits/stdc++.h>
using namespace std;
long long student[1000000];
int main() {
	long long sum = 0;
	int n;
	long long mainStudent;
	long long subStudent;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> student[i];
	}
	cin >> mainStudent >> subStudent;
	for(int j = 0; j < n; j++){
		student[j] -= mainStudent;
		if(student[j] < 0)
			student[j] = 0;
		sum++;
	}
	for(int i = 0; i < n; i++){
		sum += (student[i] / subStudent);
		student[i] = student[i] % subStudent;
		if(student[i] > 0)
			sum++;
	}
	cout << sum;
	return 0;
}