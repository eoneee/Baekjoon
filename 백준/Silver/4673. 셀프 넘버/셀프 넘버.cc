#include<bits/stdc++.h>

using namespace std;

bool selfNumber[10001];

int d(int s){
	int a = s;
	
	while(s){
		a += s % 10;
		s /= 10;
	}
	
	return a;
}

int main(){
	
	fill(selfNumber, selfNumber+10001, true);
	
	for(int i=0; i<10000; i++){
		if(d(i) <= 10000 && i < d(i)){
			selfNumber[d(i)] = false;
		}
	}
	
	for(int i=1; i<=10000; i++){
		if(selfNumber[i])
			cout << i << "\n";
	}
	return 0;
}