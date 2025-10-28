#include<bits/stdc++.h>
using namespace std;
string pattern;
int n;
string words, pre, suf;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> pattern;
	int position = pattern.find('*');
	pre = pattern.substr(0, position);
	suf = pattern.substr(position + 1);
	for(int i = 0; i < n; i++){
		cin >> words;
		if(pre.size() + suf.size() > words.size()){
			cout << "NE\n";
		}else{
			if(pre == words.substr(0, pre.size()) && suf == words.substr(words.size() - suf.size())) cout << "DA\n";
			else cout << "NE\n";
		}
	}
	

	return 0;
	
}