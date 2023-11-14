#include <bits/stdc++.h>
using namespace std;
int cnt;

 bool isDevilNum(int num){
 	string temp = to_string(num);
 	for(int i = 1; i < temp.length() - 1 ; i++){
 		if(temp[i] == temp [i-1] && temp[i] == temp[i+1] && temp[i] == '6'){
 			return true;
 		}
 	}
 	return false;
 }
//bool isDevilNum(int num){
//	string temp = to_string(num);
//	for(int i = 0; i < int(temp.length()) - 2 ; i++){
//		if(temp[i] == temp [i+1] && temp[i] == temp[i+2] && temp[i] == '6'){
//			return true;
//		}
//	}
//	return false;
//}

int main() {
	int n;
	cin >> n;
	for(int i = 1; ;i++){
		if(isDevilNum(i)){
			cnt++;
			if(cnt == n){
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}