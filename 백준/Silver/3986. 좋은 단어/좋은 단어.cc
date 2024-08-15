#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 0;
	
	
	for(int i = 0; i < n; i++){
		string temp;
		cin >> temp;
		stack<char> stackk;
		
		for(char word : temp){
			if(!stackk.empty() && stackk.top() == word){
				stackk.pop();
			}else{
				stackk.push(word);
			}
		}
		
		if(stackk.empty()){
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}