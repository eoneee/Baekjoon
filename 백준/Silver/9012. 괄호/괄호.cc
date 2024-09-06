#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	while(n--){
		stack<char> stackk;
		string s;
		cin >> s;
		
		bool flag = true;
		for(auto i : s){
			if(i == '('){
				stackk.push(i);
			}
			else{
				if(!stackk.empty() && stackk.top() == '(')
					stackk.pop();
				else
				{
					flag = false;
					break;
					
				}
			}
		}
		if(flag && stackk.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}