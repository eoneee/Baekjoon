#include<bits/stdc++.h>
using namespace std;
vector<string> name;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<char> ans;
	int n;
	cin >> n;
	string temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		name.push_back(temp);
	}
	for(int i = 0; i < n; i++){
	int cnt = 0;
		for(int j = i + 1; j < n; j++){
			if(name[i][0] == name[j][0]){
				cnt ++;
				if(cnt >= 4){
					ans.push_back(name[i][0]);
				}
				//cout << name[i];			
			}
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	if(ans.empty()) cout << "PREDAJA";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
	return 0;
}