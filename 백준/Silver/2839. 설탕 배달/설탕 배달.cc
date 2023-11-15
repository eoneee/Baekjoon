#include <iostream>
using namespace std;
int input;
int less;
int ans;
int main(){
	cin >> input;
	while(input > 0){
		if(input%5 == 0){
			ans += input/5;
			cout << ans;
			return 0;
		}
		if(input < 3){
			ans = - 1;
			cout << ans;
			return 0;
		}
		input -= 3;
		ans++;
	}
	cout << ans;
}