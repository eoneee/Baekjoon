#include <bits/stdc++.h>
using namespace std;

int main() {
		int N;
		cin >> N;
		string ans;
		vector<pair<string, string>> word(N); //배열
		for (int i = 0; i < N; ++i) {
			cin >> word[i].first >> word[i].second;
			for(int j = 0; j < word[i].first.size(); j++){
				if(word[i].first[j] == 'x' || word[i].first[j] == 'X'){
					ans += toupper(word[i].second[j]);
				}
			}
		}
	
		cout << ans << endl;

		return 0;
}
