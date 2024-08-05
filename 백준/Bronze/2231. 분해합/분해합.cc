#include <iostream>
using namespace std;
int main() {
	int n;
	int ans = 0;
	cin >> n;
	
	for(int i = 1; i < n; i ++){
		int sum = i;
		int j = i;
		while(j != 0){
			sum += j % 10;
			j /= 10;
		}
		if(sum == n){
			ans = i;
			break;
		}
	}
		cout << ans;
	return 0;
}