#include<bits/stdc++.h>
using namespace std;
int alphabet[26];
string temp;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> temp;
	for(int i = 0; i < temp.length(); i++){
		alphabet[temp[i] -'a']++;	
		//cout << temp[i] << "\n";
	}
	
	for(int i = 0; i < 26; i++){
		cout << alphabet[i] << " ";
	}
	return 0;
}