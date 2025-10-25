#include<bits/stdc++.h>
using namespace std;
string word;

bool checkPelindrom(string input){
	vector<char> ans;
	string chk;
	for(int i = 0; i < input.length(); i++){
		ans.push_back(input[i]);
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		chk += ans[i];
	}
	if(chk == input) return true;
	
	return false;
}

int main(){
	cin >> word;
	
	//if(checkPelindrom(word)) return 1;
	cout << (checkPelindrom(word) ? "1" : "0");
	return 0;
	
}